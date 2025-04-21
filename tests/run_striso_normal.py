import os
import sys

sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from src.adapter.striso.striso import StrisoAdapter
from src.config.config import ConfigFactory
from src.fuzzer import Fuzzer
import time
import json

fmt_firmware_base = "/home/ubuntu/lab/striso-control-firmware"
fmt_firmware_build_base = "/home/ubuntu/lab/striso-control-firmware/build"
thread_functions_file_path = "src/adapter/striso/thread_functions.json"

target_thread_functions = [
    "synthThread",
    "ThreadReadButtons",
    "synthThread",
    "AuxJack",
    "ThreadSend",
    "Thread1",
    "main",
]
# Set config file path for creating config.h
config = ConfigFactory("src/adapter/striso/macros.json")

build_commands = []
adapter = StrisoAdapter(
    fmt_firmware_base,
    build_commands,
    thread_functions_file_path=thread_functions_file_path,
    verbose=True,
    build_base=fmt_firmware_build_base,
)

fuzzer = Fuzzer(fmt_firmware_base, adapter, config=config, verbose=True)
# fuzzer.initial_analyze(target_thread_functions, "initial_analyze_striso")

# 24시간(86400초) 제한 설정
start_program = time.time()
MAX_RUNTIME = 86400  # 24시간을 초단위로 표시

while True:
    for target_thread in target_thread_functions:
        # 전체 실행 시간 체크
        if time.time() - start_program > MAX_RUNTIME:
            print("24시간이 경과하여 프로그램을 종료합니다.")
            break

        start_time = time.time()
        fuzzer.fuzz(methods=[])
        end_time = time.time()
        print(f"Time taken: {end_time - start_time} seconds")

        # input(
        #     "Press Enter to continue...",
        # )

        fuzzer.mutate([target_thread], methods=[])
