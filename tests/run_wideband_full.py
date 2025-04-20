import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from src.adapter.wideband.wideband import WidebandAdapter
from src.config.config import ConfigFactory
from src.config.conditional_config import Condition
from src.fuzzer import Fuzzer
import json
import time

wideband_base = "/home/ubuntu/lab/wideband/firmware"
wideband_build_dir = "/home/ubuntu/lab/wideband/firmware/build"
thread_functions_file_path = "src/adapter/wideband/thread_functions.json"

target_thread_functions = [
    "usb_msd_worker",
    "usb_debug_thread",
    "rfIntThread",
    "rfEvtThread",
    "flashWriteThread",
    "AuxOutThread",
    "CanTxThread",
    "HeaterThread",
    "IndicationThread",
    "PumpThread",
    "SamplingThread",
    "UartThread",
    "BootloaderThread",
    "StaticThreadTaskAdapter",
    "kLineThread",
    "MMCmonThread",
    "drv8860_driver_thread",
    "l9779_driver_thread",
    "mc33810_driver_thread",
    "mc33972_driver_thread",
    "tle6240_driver_thread",
    "tle8888_driver_thread",
    "tle9104_driver_thread",
    "SentDecoderThread",
    "GpsThreadEntryPoint",
    "hipThread",
]

# Set config file path for creating config.h
condition = Condition("src/adapter/wideband/condition_analysis_result.json")
config = ConfigFactory("src/adapter/wideband/macros.json", condition)


build_commands = []
adapter = WidebandAdapter(
    wideband_base,
    build_commands,
    thread_functions_file_path=thread_functions_file_path,
    verbose=True,
    build_base=wideband_build_dir,
)
adapter.initial_analyze(target_thread_functions)


fuzzer = Fuzzer(wideband_base, adapter, config=config, verbose=True)

# 24시간(86400초) 제한 설정
start_program = time.time()
MAX_RUNTIME = 86400  # 24시간을 초단위로 표시


while True:
    # 전체 실행 시간 체크
    if time.time() - start_program > MAX_RUNTIME:
        print("24시간이 경과하여 프로그램을 종료합니다.")
        break

    start_time = time.time()
    fuzzer.fuzz(methods=["related"])
    end_time = time.time()
    print(f"Time taken: {end_time - start_time} seconds")

    # input("Press Enter to continue...")
    fuzzer.mutate(target_thread_functions, methods=["related", "sat-validate"])
