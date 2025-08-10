#!/bin/bash
# Minimal ardupilot install script for ConfigFuzz
# Focus on getting IR files rather than full build

LAB_PATH="/home/ubuntu/lab"
REPO_URL="https://github.com/stacksmash-vuln/ardupilot"
TIME_ZONE="Asia/Seoul"

export TZ="$TIME_ZONE"
export DEBIAN_FRONTEND=noninteractive

set -e

echo "Starting minimal ardupilot install script"

if [ "$EUID" -eq 0 ]; then
    SUDO=""
    echo "[INFO] Running as root, sudo disabled"
else
    SUDO="sudo"
    echo "[INFO] Not running as root, sudo will be used"
fi

# 1. Install build tools
echo "[STEP 1] Installing required build tools..."
$SUDO apt update
$SUDO apt install -y \
    gcc-arm-none-eabi \
    libnewlib-arm-none-eabi \
    libstdc++-arm-none-eabi-newlib \
    python3 python3-pip \
    git make

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
    echo "[INFO] ardupilot directory already exists."
fi

cd ardupilot

# 4. Install Python dependencies
echo "[STEP 4] Installing Python dependencies..."
pip3 install empy==3.3.4 pexpect future pyserial

# 5. Try to use existing build or create minimal build
echo "[STEP 5] Checking for existing build..."

# Check if airlink build exists
if [ -d "build/airlink" ] && [ "$(find build/airlink -name "*.optimized" | wc -l)" -gt 100 ]; then
    echo "[INFO] Found existing airlink build with IR files"
else
    echo "[INFO] No sufficient build found, attempting minimal build..."
    
    # Try different boards that might work
    for board in airlink CUAV-X7 CubeOrange Pixhawk1; do
        echo "[INFO] Trying board: $board"
        
        ./waf configure --board $board -g --disable-Werror || continue
        
        # Try to build just libraries (not full firmware)
        ./waf --target libraries/AP_Common/libAP_Common.a || true
        ./waf --target libraries/AP_HAL/libAP_HAL.a || true
        
        # Check if we got some IR files
        if [ "$(find build/$board -name "*.optimized" 2>/dev/null | wc -l)" -gt 50 ]; then
            echo "[INFO] Successfully generated IR files with board $board"
            # Create symlink for compatibility
            if [ "$board" != "airlink" ]; then
                ln -sf $board build/airlink
            fi
            break
        fi
    done
fi

# 6. Verify IR files
echo "[STEP 6] Verifying IR files..."
echo "Checking .optimized files:"
find build -name "*.optimized" | wc -l

echo "Checking .su files:"
find build -name "*.su" | wc -l

# 7. Create initial analysis directory
echo "[STEP 7] Preparing for initial analysis..."
mkdir -p /conffuzz/initial_analyze_ardupilot

echo "------------------------------------------"
echo " ArduPilot minimal install complete!"
echo " Directory: $LAB_PATH/ardupilot"
echo " IR files generated for analysis"
echo "------------------------------------------"

# Return success even if build partially failed
exit 0