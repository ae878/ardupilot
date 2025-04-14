import logging as lg
from rich.console import Console
from rich.logging import RichHandler
from rich.theme import Theme

# Rich 콘솔 설정
theme = Theme({"debug": "cyan", "info": "green", "warning": "yellow", "error": "red", "critical": "red on white"})
console = Console(theme=theme)

# Rich 핸들러 설정
handler = RichHandler(
    console=console,
    rich_tracebacks=True,
    show_time=True,  # 시간 표시 활성화
    show_path=True,  # 파일 경로 표시 활성화
    enable_link_path=True,  # 파일 경로 클릭 가능하도록 설정
)

# 핸들러 포맷 설정
formatter = lg.Formatter(
    # 모듈명과 함수명을 포함한 포맷
    "%(module)s.%(funcName)s: %(message)s"
)
handler.setFormatter(formatter)


def get_logger(name: str, level: int = lg.INFO) -> lg.Logger:
    """
    모듈별 로거를 생성하고 반환합니다.

    Args:
        name (str): 로거의 이름 (보통 __name__을 사용)
        level (int): 로깅 레벨 (기본값: INFO)

    Returns:
        lg.Logger: 설정된 로거 객체
    """
    logger = lg.getLogger(name)
    logger.setLevel(level)

    # 핸들러가 이미 추가되어 있지 않은 경우에만 추가
    if not logger.handlers:
        logger.addHandler(handler)

    # propagate를 False로 설정하여 상위 로거로 전파되지 않도록 함
    logger.propagate = False

    return logger


# 루트 로거의 propagate를 False로 설정하여 중복 로깅 방지
root_logger = lg.getLogger()
root_logger.propagate = False

# 다른 파일에서 import할 수 있도록 logging 이름으로 export
logging = root_logger
