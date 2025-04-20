import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from src.adapter.px4.px4 import PX4Adapter
from src.config.conditional_config import Condition
from src.config.config import ConfigFactory
from src.fuzzer import Fuzzer
import json
import time

px4_base = "/home/ubuntu/lab/PX4-Autopilot"
px4_build_base = "/home/ubuntu/lab/PX4-Autopilot/build"
thread_functions_file_path = "src/adapter/px4/thread_functions.json"

target_thread_functions = [
    "px4::WorkQueueManagerRun",
    "ModuleBase<GPS>::run_trampoline",
    "GPS::run_trampoline_secondary",
    "frsky_telemetry_thread_main",
    "hott_sensors_thread_main",
    "hott_telemetry_thread_main",
    "ModuleBase<Commander>::run_trampoline",
    "task_main",
    "gimbal_thread_main",
    "landing_target_estimator::landing_target_estimator_thread_main",
    "ModuleBase<px4::logger::Logger>::run_trampoline",
    "MavlinkShell::shell_start_thread",
    "Mavlink::start_helper",
    "ModuleBase<Navigator>::run_trampoline",
    "ModuleBase<Sih>::run_trampoline",
    "TemperatureCalibration::do_temperature_calibration",
    "ModuleBase<UxrceddsClient>::run_trampoline",
]
condition = Condition("src/adapter/px4/condition_analysis_result.json")
config = ConfigFactory("src/adapter/px4/macros.json", condition=condition)

# header_file = config.create_config_header()


build_commands = []
adapter = PX4Adapter(
    px4_base,
    build_commands,
    thread_functions_file_path=thread_functions_file_path,
    verbose=True,
    build_base=px4_build_base,
)


fuzzer = Fuzzer(px4_base, adapter, config=config, verbose=True)
# fuzzer.initial_analyze(target_thread_functions)

# 24시간(86400초) 제한 설정
start_program = time.time()
MAX_RUNTIME = 86400  # 24시간을 초단위로 표시


while True:
    # 전체 실행 시간 체크
    if time.time() - start_program > MAX_RUNTIME:
        print("24시간이 경과하여 프로그램을 종료합니다.")
        break

    start_time = time.time()
    fuzzer.fuzz(methods=[])
    end_time = time.time()
    print(f"Time taken: {end_time - start_time} seconds")

    # input("Press Enter to continue...")
    fuzzer.mutate(target_thread_functions, methods=["sat-validate"])
