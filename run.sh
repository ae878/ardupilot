#!/bin/bash
cd /conffuzz

# 환경 변수 설정
export PYTHONUNBUFFERED=1

echo "Starting ConfigFuzz for $ACTIVE_SCRIPT..."

# 실행
if [ "$1" = "test" ]; then
    # 테스트 모드: 짧은 실행
    timeout 300 python3 tests/run.py -t $ACTIVE_SCRIPT -r -s
elif [ "$1" = "dry-run" ]; then
    # Dry-run 모드
    python3 tests/run.py -t $ACTIVE_SCRIPT -d
else
    # 정상 실행
    python3 tests/run.py -t $ACTIVE_SCRIPT -r -s
fi