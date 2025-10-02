# syntax=docker/dockerfile:1.4
# BuildKit 구문 사용을 명시하여 --mount=type=ssh 등의 기능 활용 가능

# --- 빌드 아규먼트 선언 ---

FROM --platform=linux/x86_64 ubuntu:22.04

ARG SCRIPT_TO_RUN="wideband" # 기본값을 'base'로 설정
ARG GIT_TOKEN             # Git 토큰을 받을 변수
ENV ACTIVE_SCRIPT=${SCRIPT_TO_RUN}

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Etc/UTC

RUN echo "Running with $ACTIVE_SCRIPT" 

RUN mkdir -p /conffuzz
# 작업 디렉토리 설정
WORKDIR /conffuzz
COPY . .

RUN apt-get update && apt-get install -y --no-install-recommends \
    git \
    openssh-client \
    curl \
    ca-certificates \
    python3 \
    python3-pip \
    python3-dev \
    gcc g++ \
    libgraphviz-dev \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install -r requirements.txt

# 스크립트에 실행 권한 부여
RUN chmod +x scripts/install/*.sh

# 2. SCRIPT_TO_RUN args를 이용해 그 args에 따라서 install/install_[SCRIPTS_TO_RUN].sh 실행
# 3. 해당 스크립트 안에다가 args로 받은 GIT_TOKEN 전달
# BuildKit의 --mount=type=ssh를 사용하여 SSH 클론 시 키를 노출하지 않습니다.
# 만약 HTTPS + PAT (Personal Access Token) 방식이라면 아래 주석 처리된 부분을 사용하세요.
RUN export GIT_TOKEN="${GIT_TOKEN}" && \
    if [ -f "scripts/install/install_${ACTIVE_SCRIPT}.sh" ]; then \
        echo "Executing scripts/install/install_${ACTIVE_SCRIPT}.sh with GIT_TOKEN..."; \
        # 스크립트에 환경 변수로 GIT_TOKEN을 전달하여 실행
        ./scripts/install/install_${ACTIVE_SCRIPT}.sh; \
    else \
        echo "Error: install_${ACTIVE_SCRIPT}.sh not found. No script executed."; \
        exit 1; \
    fi


CMD ["tail", "-f", "/dev/null"]
