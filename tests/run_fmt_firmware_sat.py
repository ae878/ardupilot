import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from src.adapter.fmt_controller.fmt_controller import FMTControllerAdapter
from src.config.config import ConfigFactory
from src.fuzzer import Fuzzer
import time
import json

fmt_firmware_base = "/home/ubuntu/lab/FMT-Firmware"
fmt_firmware_build_base = "/home/ubuntu/lab/FMT-Firmware/target/amov/icf5/build"
thread_functions_file_path = "src/adapter/fmt_controller/thread_functions.json"

target_thread_functions = [
    "task_status_entry",
    "task_mavgcs_entry",
    "task_mavobc_entry",
    "task_logger_entry",
    "task_vehicle_entry",
    "task_fmtio_entry",
    "gps_probe_entry",
    "rt_init_thread_entry",
    "workqueue_executor",
    "thread_entry",
    "task_dronecan_entry",
]
# Set config file path for creating config.h
config = ConfigFactory("src/adapter/fmt_controller/macros.json")

build_commands = []
adapter = FMTControllerAdapter(
    fmt_firmware_base,
    build_commands,
    thread_functions_file_path=thread_functions_file_path,
    verbose=True,
    build_base=fmt_firmware_build_base,
)


fuzzer = Fuzzer(fmt_firmware_base, adapter, config=config, verbose=True)
# fuzzer.applyer.apply(config, target_macros=["FMT_LOG_LEVEL"])
fuzzer.initial_analyze(target_thread_functions, "initial_analyze_fmt")

# 24시간(86400초) 제한 설정
start_program = time.time()
MAX_RUNTIME = 86400  # 24시간을 초단위로 표시

while True:
    # for target_thread in target_thread_functions:
    # 전체 실행 시간 체크
    if time.time() - start_program > MAX_RUNTIME:
        print("24시간이 경과하여 프로그램을 종료합니다.")
        break

    start_time = time.time()
    fuzzer.fuzz(methods=["sat-validate"])
    end_time = time.time()
    print(f"Time taken: {end_time - start_time} seconds")

    # input(
    #     "Press Enter to continue...",
    # )

    fuzzer.mutate(target_thread_functions, methods=["sat-validate"])
