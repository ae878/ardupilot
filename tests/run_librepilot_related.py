import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from src.adapter.librepilot.librepilot import LibrepilotAdapter
from src.config.config import ConfigFactory
from src.config.conditional_config import Condition
from src.fuzzer import Fuzzer
import json
import time

librepilot_base = "/home/ubuntu/lab/LibrePilot"
librepilot_build_base = "/home/ubuntu/lab/LibrePilot/build/firmware"
thread_functions_file_path = "src/adapter/librepilot/thread_functions.json"

target_thread_functions = [
    "writeTask",
    "eventTask",
    "pathPlannerTask",
    "updatePathDesired",
    "manualControlTask",
    "CameraControlTask",
    "altitudeHoldTask",
    "stabilizationOuterloopTask",
    "stabilizationInnerloopTask",
    "pathFollowerTask",
    "main",
    "actuatorTask",
    "com2UsbBridgeTask",
    "usb2ComBridgeTask",
    "SensorsTask",
    "uavoFrSKYSensorHubBridgeTask",
    "AutoTuneTask",
    "gpsTask",
    "telemetryTxTask",
    "telemetryRxTask",
    "telemetryTxTask",
    "telemetryRxTask",
    "AttitudeTask",
    "telemetryTxTask",
    "telemetryRxTask",
    "uavoMavlinkBridgeTask",
    "uavoMSPBridgeTask",
    "receiverTask",
    "systemTask",
    "overoSyncTask",
    "magbaroTask",
    "osdgenTask",
    "osdinputTask",
    "WavPlayerTask",
    "flightPlanTask",
    "MkSerialTask",
    "fault_task",
    "telemRadioTxTask",
    "telemRadioRxTask",
    "PPMInputTask",
    "gpspSystemTask",
]
# Set config file path for creating config.h
condition = Condition("src/adapter/librepilot/condition_analysis_result.json")
config = ConfigFactory("src/adapter/librepilot/macros.json", condition=condition)
# header_file = config.create_config_header()


build_commands = []
adapter = LibrepilotAdapter(
    librepilot_base,
    build_commands,
    thread_functions_file_path=thread_functions_file_path,
    verbose=True,
    build_base=librepilot_build_base,
)


fuzzer = Fuzzer(librepilot_base, adapter, config=config, verbose=True)
fuzzer.initial_analyze(target_thread_functions)

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
    fuzzer.mutate(target_thread_functions, methods=["related"])
