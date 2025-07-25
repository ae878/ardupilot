#!/bin/bash
# Tested with: Docker w/ubuntu 22.04 image
# docker pull --platform=linux/x86_64 ubuntu:22.04
# docker run --platform=linux/x86_64 -it ubuntu:22.04
LAB_PATH="/home/ubuntu/lab"
REPO_URL="https://github.com/stacksmash-vuln/TauLabs"
TIME_ZONE="Asia/Seoul"

export TZ="$TIME_ZONE"

set -e

echo "Starting TauLabs install script"

if [ "$EUID" -eq 0 ]; then
    SUDO=""
    echo "[INFO] Running as root, sudo disabled"
else
    SUDO="sudo"
    echo "[INFO] Not running as root, sudo will be used"
    if ! command -v sudo >/dev/null 2>&1; then
        echo "[ERROR] sudo not found. Please install sudo first."
        exit 1
    fi
fi

# 1. Install build tools
echo "[STEP 1] Installing required build tools..."

$SUDO apt update
$SUDO apt-get update
$SUDO apt install tzdata
$SUDO ln -fs /usr/share/zoneinfo/$TIME_ZONE /etc/localtime
$SUDO dpkg-reconfigure --frontend noninteractive tzdata

$SUDO apt install -y curl wget make bzip2 git build-essential vim

$SUDO dpkg --add-architecture i386
$SUDO apt-get install -y gcc-multilib


# 2. Create working directory
echo "[STEP 2] Creating lab directory at $LAB_PATH"
mkdir -p "$LAB_PATH"
cd "$LAB_PATH"

# 3. Clone TauLabs
if [ ! -d TauLabs ]; then
    echo "[STEP 3] Cloning TauLabs repository..."
    git clone --recurse-submodules "$REPO_URL"
else
    echo "[INFO] TauLabs directory already exists. Updating repo."
    cd TauLabs
    git pull
    git submodule update --init --recursive
    cd ..
fi

cd TauLabs

# 4. Install ARM SDK
echo "[STEP 4] Installing ARM SDK..."
make arm_sdk_install

# 5. Install TauLabs dependencies
echo "[STEP 5] Installing Qt dependencies..."
$SUDO apt-get install -y python2 qt5-qmake qtbase5-dev qtbase5-dev-tools libqt5svg5-dev libqt5webenginewidgets5 libqt5webchannel5-dev qtwebengine5-dev

# 6. Build firmware
echo "[STEP 6] Building Sparky2 firmware..."
make fw_sparky2

echo "------------------------------------------"
echo " TauLabs install complete! "
echo " Directory: $LAB_PATH/TauLabs "
echo " Build success! "
echo "------------------------------------------"
