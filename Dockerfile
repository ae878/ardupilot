# syntax=docker/dockerfile:1.4
# BuildKit 구문 사용을 명시하여 --mount=type=ssh 등의 기능 활용 가능

# --- 빌드 아규먼트 선언 ---
FROM --platform=linux/x86_64 ubuntu:22.04

ARG SCRIPT_TO_RUN="ardupilot" # 기본값
ARG GIT_TOKEN             # Git 토큰을 받을 변수
ENV ACTIVE_SCRIPT=${SCRIPT_TO_RUN}

RUN echo "Running with $ACTIVE_SCRIPT" 

# 환경 변수 설정
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Seoul

# 기본 패키지 설치
RUN apt-get update && apt-get install -y --no-install-recommends \
    git \
    openssh-client \
    curl \
    wget \
    ca-certificates \
    python3 \
    python3-pip \
    python3-dev \
    gcc g++ \
    libgraphviz-dev \
    build-essential \
    make \
    bzip2 \
    vim \
    # ARM 툴체인 설치 (중요!)
    gcc-arm-none-eabi \
    libnewlib-arm-none-eabi \
    libstdc++-arm-none-eabi-newlib \
    gdb-multiarch \
    && rm -rf /var/lib/apt/lists/*

# 작업 디렉토리 설정
RUN mkdir -p /conffuzz
WORKDIR /conffuzz
COPY . .

# Python 패키지 설치
RUN pip3 install -r requirements.txt

# 스크립트에 실행 권한 부여
RUN chmod +x scripts/install/*.sh

# 프로젝트별 설치 스크립트 실행 (에러 허용)
RUN export GIT_TOKEN="${GIT_TOKEN}" && \
    if [ -f "scripts/install/install_${ACTIVE_SCRIPT}.sh" ]; then \
        echo "Executing scripts/install/install_${ACTIVE_SCRIPT}.sh..."; \
        ./scripts/install/install_${ACTIVE_SCRIPT}.sh || { \
            echo "Warning: install script had errors, but continuing..."; \
            echo "Some build artifacts may be missing"; \
        }; \
    else \
        echo "Error: install_${ACTIVE_SCRIPT}.sh not found."; \
        exit 1; \
    fi

# ArduPilot의 경우 추가 설정
RUN if [ "$ACTIVE_SCRIPT" = "ardupilot" ]; then \
    # build_commands.json 경로 수정
    cd /conffuzz && \
    sed -i 's|"directory": "/home/ubuntu/lab/ardupilot/build/R9Pilot"|"directory": "/home/ubuntu/lab/ardupilot/build/airlink"|g' src/adapter/ardupilot/build_commands.json && \
    # specs 파일 경로 수정
    sed -i 's|--specs=nano.specs|--specs=/usr/lib/arm-none-eabi/newlib/nano.specs|g' src/adapter/ardupilot/build_commands.json && \
    sed -i 's|--specs=nosys.specs|--specs=/usr/lib/arm-none-eabi/newlib/nosys.specs|g' src/adapter/ardupilot/build_commands.json && \
    # 컴파일러 경로 수정
    sed -i 's|/opt/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-g++|arm-none-eabi-g++|g' src/adapter/ardupilot/build_commands.json && \
    # tests/run.py 경로 수정
    sed -i 's|"build_base": "/home/ubuntu/lab/ardupilot/build/R9Pilot"|"build_base": "/home/ubuntu/lab/ardupilot/build/airlink"|g' tests/run.py; \
fi

# 초기 분석 결과를 미리 생성 (옵션)
RUN if [ "$ACTIVE_SCRIPT" = "ardupilot" ]; then \
    cd /conffuzz && \
    mkdir -p initial_analyze_ardupilot && \
    echo "Initial analyze will be created on first run"; \
fi

# 실행 스크립트 복사 (이미 파일로 존재)
# COPY run.sh /conffuzz/run.sh는 이미 COPY . . 에서 처리됨

RUN chmod +x /conffuzz/run.sh

# 헬스체크 추가
HEALTHCHECK --interval=30s --timeout=10s --start-period=5s --retries=3 \
    CMD ps aux | grep python3 || exit 1

# 기본 실행 명령 (계속 실행되도록)
CMD ["tail", "-f", "/dev/null"]