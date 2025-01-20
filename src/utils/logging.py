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

# 로거 설정
logger = lg.getLogger("")
logger.setLevel(lg.DEBUG)

# 핸들러 포맷 설정
formatter = lg.Formatter(
    # 모듈명과 함수명을 포함한 포맷
    "%(module)s.%(funcName)s: %(message)s"
)
handler.setFormatter(formatter)

# 핸들러 추가
logger.addHandler(handler)

# 다른 파일에서 import할 수 있도록 logging 이름으로 export
logging = logger
