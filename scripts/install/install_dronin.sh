#!/bin/bash
# Tested with: Docker w/ubuntu 22.04 image
# docker pull --platform=linux/x86_64 ubuntu:22.04
# docker run --platform=linux/x86_64 -it ubuntu:22.04
LAB_PATH="/home/ubuntu/lab"
REPO_URL="https://github.com/stacksmash-vuln/dRonin"
TIME_ZONE="Asia/Seoul"

export TZ="$TIME_ZONE"
export DEBIAN_FRONTEND=noninteractive

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

# 1.5. Install Python 3.7
echo "[STEP 1.5] Installing Python 3.7..."
$SUDO apt install -y software-properties-common
$SUDO add-apt-repository ppa:deadsnakes/ppa -y
$SUDO apt update
$SUDO apt install -y python3.7 python3.7-dev python3.7-distutils python3.7-venv
$SUDO apt install -y python3-pip

# Set Python 3.7 as default python3
$SUDO update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.7 1
$SUDO update-alternatives --install /usr/bin/python python /usr/bin/python3.7 1

# Verify Python installation
echo "[INFO] Python version: $(python --version)"
echo "[INFO] Python3 version: $(python3 --version)"

# 2. Create working directory
echo "[STEP 2] Creating lab directory at $LAB_PATH"
mkdir -p "$LAB_PATH"
cd "$LAB_PATH"

# 3. Clone dRonin
if [ ! -d dRonin ]; then
    echo "[STEP 3] Cloning dRonin repository..."
    git clone --recurse-submodules "$REPO_URL"
else
    echo "[INFO] dRonin directory already exists. Updating repo."
    cd dRonin
    git pull
    git submodule update --init --recursive
    cd ..
fi

cd dRonin

# 4. Install dRonin dependencies
echo "[STEP 4] Installing Qt dependencies..."
$SUDO apt-get install -y qt5-qmake qtbase5-dev qtbase5-dev-tools libqt5svg5-dev libqt5webenginewidgets5 libqt5webchannel5-dev qtwebengine5-dev
$SUDO apt-get install -y python-is-python3

# 5. Install ARM SDK
echo "[STEP 5] Installing ARM SDK..."
make arm_sdk_install


# 6. Build firmware
echo "[STEP 6] Building Sparky2 firmware..."
make fw_sparky2

echo "------------------------------------------"
echo " dRonin install complete! "
echo " Directory: $LAB_PATH/dRonin "
echo " Build success! "
echo "------------------------------------------"
