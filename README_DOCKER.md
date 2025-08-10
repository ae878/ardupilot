# ConfigFuzz Docker 개선 가이드

## 문제점 해결

### 1. 발견된 문제들
- ❌ ARM 툴체인 불완전 설치 (specs 파일 누락)
- ❌ 초기 분석 타임아웃
- ❌ Applier 파일 경로 오류

### 2. 해결 방법

#### 방법 1: 개선된 Dockerfile 사용 (권장)

```bash
# 기존 Dockerfile 백업
cp Dockerfile Dockerfile.original

# 개선된 Dockerfile 사용
cp Dockerfile.improved Dockerfile

# 개선된 설치 스크립트 사용
cp scripts/install/install_ardupilot_improved.sh scripts/install/install_ardupilot.sh

# Docker 이미지 빌드
docker build --build-arg SCRIPT_TO_RUN=ardupilot -t configfuzz:ardupilot .

# 실행
docker run -d --name fuzz_ardupilot_improved configfuzz:ardupilot
```

#### 방법 2: Docker Compose 사용 (더 쉬움)

```bash
# Docker Compose로 빌드 및 실행
docker-compose up -d ardupilot-fuzz

# 로그 확인
docker-compose logs -f ardupilot-fuzz

# 중지
docker-compose down
```

#### 방법 3: 개선된 스크립트로 직접 실행

```bash
# 컨테이너 접속
docker exec -it fuzz_ardupilot_improved bash

# 개선된 스크립트 실행
cd /conffuzz
python3 run_improved.py --timeout 300 --threads 5 -r -s

# 옵션 설명:
# --timeout 300: 5분 실행
# --threads 5: 5개 스레드 함수만 분석
# -r: 관련 매크로만 변이
# -s: SAT solver 사용
# --skip-build: 빌드 단계 건너뛰기
# --skip-initial: 초기 분석 건너뛰기
# --dry-run: 실제 퍼징 없이 테스트
```

## 주요 개선사항

### 1. Dockerfile.improved
- ✅ gcc-arm-none-eabi 제대로 설치
- ✅ 빌드 경로 자동 수정
- ✅ 헬스체크 추가
- ✅ 실행 스크립트 개선

### 2. install_ardupilot_improved.sh
- ✅ ARM 툴체인 확인 및 설치
- ✅ 전체 타겟 빌드 (rover만이 아닌)
- ✅ 빌드 결과 검증
- ✅ compile_commands.json 생성

### 3. run_improved.py
- ✅ 경로 자동 수정
- ✅ 타임아웃 처리
- ✅ 에러 핸들링 개선
- ✅ 진행 상황 리포트
- ✅ pickle 캐시 활용

## 실행 예시

### 빠른 테스트 (5분)
```bash
docker run --rm -it configfuzz:ardupilot \
    python3 run_improved.py --timeout 300 --threads 5 -r -s --quick-test
```

### 장시간 실행
```bash
docker run -d --name ardupilot_fuzz \
    -v $(pwd)/output:/conffuzz/output \
    configfuzz:ardupilot \
    python3 run_improved.py --timeout 86400 -r -s
```

### 결과 확인
```bash
# 실시간 모니터링
docker exec -it ardupilot_fuzz bash -c "watch -n 2 'ls -la output/ | tail -10'"

# 스택 오버플로우 확인
docker exec -it ardupilot_fuzz bash -c "
for f in output/*_function_results.json; do
    python3 -c \"
import json
with open('\$f') as fp:
    results = json.load(fp)
    for r in results:
        if r['biggest_stack'] > r['source_size']:
            print(f'OVERFLOW in \$f: {r[\"name\"]}')
    \"
done
"
```

## 문제 해결

### ARM 툴체인 문제
```bash
# 컨테이너 내부에서
apt-get update && apt-get install -y gcc-arm-none-eabi
```

### 빌드 경로 문제
```bash
# 자동으로 수정되지만 수동으로 하려면
sed -i 's/R9Pilot/airlink/g' src/adapter/ardupilot/build_commands.json
```

### 메모리 부족
```bash
# Docker 메모리 증가
docker run -m 8g ...
```

## 성능 팁

1. **초기 분석 캐싱**: 한 번 실행 후 pickle 파일이 생성되면 재사용
2. **병렬 빌드**: `-j4` 옵션으로 4코어 활용
3. **제한된 스레드**: 전체가 아닌 일부 스레드만 분석
4. **SAT solver**: 유효한 설정만 테스트

## 기대 결과

성공적으로 실행되면:
- `output/` 디렉토리에 JSON 결과 파일 생성
- 스택 오버플로우 발견 시 로그에 표시
- 각 단계별 진행 상황 출력