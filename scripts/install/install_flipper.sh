#!/bin/bash
# Tested with: Docker w/ubuntu 22.04 image
# docker pull --platform=linux/x86_64 ubuntu:22.04
# docker run --platform=linux/x86_64 -it ubuntu:22.04
LAB_PATH="/home/ubuntu/lab"
REPO_URL="https://github.com/stacksmash-vuln/flipperzero-firmware"
TIME_ZONE="Asia/Seoul"
DOWNLOAD_URL="https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2"
INSTALL_DIR="$HOME/arm-none-eabi-gcc"


export TZ="$TIME_ZONE"
export DEBIAN_FRONTEND=noninteractive

set -e

echo "Starting flipperzero-firmware install script"

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

$SUDO apt install -y curl wget make bzip2 git build-essential vim python3 python3-pip

$SUDO dpkg --add-architecture i386
$SUDO apt-get install -y gcc-multilib


# 2. Create working directory
echo "[STEP 2] Creating lab directory at $LAB_PATH"
mkdir -p "$LAB_PATH"
cd "$LAB_PATH"

# 3. Clone flipperzero-firmware
if [ ! -d flipperzero-firmware ]; then
    echo "[STEP 3] Cloning flipperzero-firmware repository..."
    git clone --recurse-submodules "$REPO_URL"
else
    echo "[INFO] flipperzero-firmware directory already exists. Updating repo."
    cd flipperzero-firmware
    git pull
    git submodule update --init --recursive
    cd ..
fi

cd flipperzero-firmware



# Install arm-none-eabi-gcc
mkdir -p "$INSTALL_DIR"

TMP_FILE="$INSTALL_DIR/gcc-arm-none-eabi.tar.bz2"
wget -O "$TMP_FILE" "$DOWNLOAD_URL"
tar -xjf "$TMP_FILE" -C "$INSTALL_DIR"
rm "$TMP_FILE"

EXTRACTED_DIR=$(find "$INSTALL_DIR" -maxdepth 1 -type d -name "gcc-arm-none-eabi-*")
EXTRACTED_DIR=$(echo "$EXTRACTED_DIR" | head -n 1)

echo "export EXEC_PATH=\"$EXTRACTED_DIR/bin\"" >> "$HOME/.bashrc"
echo "export RTT_EXEC_PATH=\"$EXTRACTED_DIR/bin\"" >> "$HOME/.bashrc"
echo "export PATH=\"\$EXEC_PATH:\$PATH\"" >> "$HOME/.bashrc"

# Apply into current shell
export EXEC_PATH="$EXTRACTED_DIR/bin"
export RTT_EXEC_PATH="$EXEC_PATH"
export PATH="$EXEC_PATH:$PATH"




# 6. Build firmware
echo "[STEP 6] Building flipperzero-firmware firmware..."
./fbt

echo "------------------------------------------"
echo " flipperzero-firmware install complete! "
echo " Directory: $LAB_PATH/flipperzero-firmware "
echo " Build success! "
echo "------------------------------------------"
