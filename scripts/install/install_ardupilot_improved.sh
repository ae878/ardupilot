#!/bin/bash
# Improved ardupilot install script for ConfigFuzz
# Tested with: Docker w/ubuntu 22.04 image

LAB_PATH="/home/ubuntu/lab"
REPO_URL="https://github.com/stacksmash-vuln/ardupilot"
TIME_ZONE="Asia/Seoul"

export TZ="$TIME_ZONE"
export DEBIAN_FRONTEND=noninteractive

set -e

echo "Starting improved ardupilot install script"

if [ "$EUID" -eq 0 ]; then
    SUDO=""
    echo "[INFO] Running as root, sudo disabled"
else
    SUDO="sudo"
    echo "[INFO] Not running as root, sudo will be used"
fi

# 1. Install build tools (이미 Dockerfile에서 설치했으므로 스킵 가능)
echo "[STEP 1] Checking required build tools..."
if ! command -v arm-none-eabi-gcc &> /dev/null; then
    echo "[WARNING] arm-none-eabi-gcc not found, installing..."
    $SUDO apt update
    $SUDO apt install -y gcc-arm-none-eabi
fi

# ARM 툴체인 버전 확인
echo "[INFO] ARM toolchain version:"
arm-none-eabi-gcc --version

# 2. Create working directory
echo "[STEP 2] Creating lab directory at $LAB_PATH"
mkdir -p "$LAB_PATH"
cd "$LAB_PATH"

# 3. Clone ardupilot
if [ ! -d ardupilot ]; then
    echo "[STEP 3] Cloning ardupilot repository..."
    git clone --recurse-submodules "$REPO_URL"
else
    echo "[INFO] ardupilot directory already exists. Updating repo."
    cd ardupilot
    git pull
    git submodule update --init --recursive
    cd ..
fi

cd ardupilot

# 4. Install Python dependencies
echo "[STEP 4] Installing Python dependencies..."
pip3 install empy==3.3.4 pexpect future pyserial

# 5. Configure waf (중요: 경로명 통일)
echo "[STEP 5] Configuring waf for airlink board..."
./waf configure \
    --board airlink \
    -g \
    --check-verbose \
    --disable-Werror \
    --notests \
    --enable-scripting \
    --enable-opendroneid \
    --enable-check-firmware \
    --enable-custom-controller \
    --enable-gps-logging \
    --enable-header-checks \
    --enable-stats

# 6. Build firmware (전체 빌드)
echo "[STEP 6] Building all targets..."
./waf build -j4

# 7. Generate compile_commands.json
echo "[STEP 7] Generating compile_commands.json..."
if [ -f "build/airlink/compile_commands.json" ]; then
    cp build/airlink/compile_commands.json /conffuzz/src/adapter/ardupilot/build_commands_generated.json
    echo "[INFO] compile_commands.json copied successfully"
else
    echo "[WARNING] compile_commands.json not found, using existing build_commands.json"
fi

# 8. Verify build results
echo "[STEP 8] Verifying build results..."
echo "Checking .optimized files:"
find build/airlink -name "*.optimized" | wc -l

echo "Checking .su files:"
find build/airlink -name "*.su" | wc -l

echo "Checking thread functions:"
if [ -f "/conffuzz/src/adapter/ardupilot/thread_functions.json" ]; then
    python3 -c "
import json
with open('/conffuzz/src/adapter/ardupilot/thread_functions.json') as f:
    threads = json.load(f)
    print(f'Total thread functions: {len(threads)}')
    for t in threads[:5]:
        print(f\"  - {t['thread']}: {t['size']} bytes\")
"
fi

# 9. Create initial analysis cache (옵션)
echo "[STEP 9] Preparing for initial analysis..."
mkdir -p /conffuzz/initial_analyze_ardupilot

echo "------------------------------------------"
echo " ArduPilot install complete!"
echo " Directory: $LAB_PATH/ardupilot"
echo " Build directory: $LAB_PATH/ardupilot/build/airlink"
echo " Build success!"
echo "------------------------------------------"

# 10. 추가 정보 출력
echo ""
echo "Build info:"
echo "- Board: airlink"
echo "- Compiler: $(arm-none-eabi-gcc --version | head -1)"
echo "- Build path: $(pwd)/build/airlink"
echo ""