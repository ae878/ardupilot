#!/bin/bash
# Apply improvements to existing files

echo "Applying ConfigFuzz improvements..."

# Backup original files
echo "[1/4] Backing up original files..."
cp Dockerfile Dockerfile.original 2>/dev/null || echo "Dockerfile already backed up"
cp scripts/install/install_ardupilot.sh scripts/install/install_ardupilot.sh.original 2>/dev/null || echo "install_ardupilot.sh already backed up"

# Apply improved files
echo "[2/4] Applying improved files..."
cp Dockerfile.improved Dockerfile
cp scripts/install/install_ardupilot_improved.sh scripts/install/install_ardupilot.sh
chmod +x scripts/install/install_ardupilot.sh

# Make run_improved.py executable
chmod +x run_improved.py

echo "[3/4] Files updated successfully!"

echo "[4/4] Build instructions:"
echo "  docker build --build-arg SCRIPT_TO_RUN=ardupilot -t configfuzz:ardupilot ."
echo "  docker run -d --name fuzz_ardupilot_improved configfuzz:ardupilot"
echo ""
echo "Or use docker-compose:"
echo "  docker-compose up -d ardupilot-fuzz"
echo ""
echo "Done!"