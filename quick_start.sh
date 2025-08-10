#!/bin/bash
# Quick start script for ConfigFuzz with ArduPilot

echo "ConfigFuzz Quick Start"
echo "====================="

# 1. 기존 컨테이너 정리
echo "[1/5] Cleaning up old containers..."
docker stop fuzz_ardupilot_minimal 2>/dev/null || true
docker rm fuzz_ardupilot_minimal 2>/dev/null || true

# 2. Minimal Dockerfile로 빌드
echo "[2/5] Building Docker image..."
docker build -f Dockerfile.minimal \
    --build-arg SCRIPT_TO_RUN=ardupilot \
    -t configfuzz:ardupilot-minimal . || {
    echo "Build failed! Trying alternative approach..."
    
    # 대안: 기본 Ubuntu 이미지에서 직접 실행
    docker run -d --name fuzz_ardupilot_minimal \
        -v $(pwd):/conffuzz \
        -w /conffuzz \
        ubuntu:22.04 \
        bash -c "
            apt-get update && \
            apt-get install -y python3 python3-pip gcc-arm-none-eabi && \
            pip3 install -r requirements.txt && \
            python3 run_improved.py --skip-build --skip-initial --timeout 300
        "
    exit 0
}

# 3. 컨테이너 실행
echo "[3/5] Starting container..."
docker run -d --name fuzz_ardupilot_minimal \
    -v $(pwd)/output:/conffuzz/output \
    configfuzz:ardupilot-minimal

# 4. 상태 확인
echo "[4/5] Checking container status..."
sleep 5
docker ps | grep fuzz_ardupilot_minimal

# 5. 로그 확인
echo "[5/5] Container logs:"
docker logs --tail 20 fuzz_ardupilot_minimal

echo ""
echo "Commands:"
echo "  Watch logs:    docker logs -f fuzz_ardupilot_minimal"
echo "  Enter shell:   docker exec -it fuzz_ardupilot_minimal bash"
echo "  Stop:          docker stop fuzz_ardupilot_minimal"
echo ""
echo "Quick test inside container:"
echo "  docker exec -it fuzz_ardupilot_minimal python3 run_improved.py --skip-build --timeout 60"