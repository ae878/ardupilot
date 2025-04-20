import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from src.adapter.taulabs.taulabs import TaulabsAdapter
from src.config.config import ConfigFactory
from src.config.conditional_config import Condition
from src.fuzzer import Fuzzer
import json
import time

taulabs_base = "/home/ubuntu/lab/TauLabs"
taulabs_build_dir = "/home/ubuntu/lab/TauLabs/build"
thread_functions_file_path = "src/adapter/taulabs/thread_functions.json"

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
condition = Condition("src/adapter/taulabs/condition_analysis_result.json")
config = ConfigFactory("src/adapter/taulabs/macros.json", condition)


build_commands = []
adapter = TaulabsAdapter(
    taulabs_base,
    build_commands,
    thread_functions_file_path=thread_functions_file_path,
    verbose=True,
    build_base=taulabs_build_dir,
)


fuzzer = Fuzzer(taulabs_base, adapter, config=config, verbose=True)
fuzzer.initial_analyze(target_thread_functions, "initial_analyze_taulabs")

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
