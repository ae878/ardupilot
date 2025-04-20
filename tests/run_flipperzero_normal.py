import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from src.adapter.flipper_zero.flippzero import FlipperZeroAdapter
from src.config.config import ConfigFactory
from src.fuzzer import Fuzzer
import json
import time

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
flipperzero_base = "/home/ubuntu/lab/flipperzero-firmware/build/latest"
flipperzero_build_base = "/home/ubuntu/lab/flipperzero-firmware/build/f7-firmware-D"
thread_functions_file_path = "src/adapter/flipper_zero/thread_functions.json"

# Set config file path for creating config.h
config = ConfigFactory("src/adapter/flipper_zero/macros.json")
# header_file = config.create_config_header()

with open("src/adapter/flipper_zero/build_commands.json", "r") as f:
    build_commands = json.load(f)

adapter = FlipperZeroAdapter(
    flipperzero_base,
    build_commands,
    thread_functions_file_path=thread_functions_file_path,
    verbose=True,
    build_base=flipperzero_build_base,
)


fuzzer = Fuzzer(flipperzero_base, adapter, config=config, verbose=True)
# fuzzer.initial_analyze("AP_InertialSensor_ADIS1647x::loop", initial_analyze_result_dir="initial_analyze_ardupilot")

while True:
    start_time = time.time()
    fuzzer.fuzz()
    end_time = time.time()
    print(f"Time taken: {end_time - start_time} seconds")

    input("Press Enter to continue...")
    fuzzer.mutate("AP_InertialSensor_ADIS1647x::loop", methods=["related", "stack"])
