import sys
import os
import json
import time
import glob
import argparse
from typing import Tuple

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from src.adapter.fmt_controller.fmt_controller import FMTControllerAdapter
from src.config.config import ConfigFactory
from src.config.conditional_config import Condition
from src.fuzzer import Fuzzer
from utils.utils import calculate_previous_runtime


def main():
    parser = argparse.ArgumentParser(description="Run FMT firmware fuzzer")
    parser.add_argument(
        "-r", "--resume", action="store_true", help="Resume from last completed step and adjust runtime"
    )
    args = parser.parse_args()

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
    condition = Condition("src/adapter/fmt_controller/condition_analysis_result.json")
    config = ConfigFactory("src/adapter/fmt_controller/macros.json", condition=condition)

    build_commands = []
    adapter = FMTControllerAdapter(
        fmt_firmware_base,
        build_commands,
        thread_functions_file_path=thread_functions_file_path,
        verbose=True,
        build_base=fmt_firmware_build_base,
    )

    # Initialize runtime variables
    MAX_RUNTIME = 86400  # 24 hours in seconds
    remaining_time = MAX_RUNTIME
    start_step = 0

    # If resume flag is set, calculate previous runtime and adjust start step
    if args.resume:
        total_previous_time, last_step = calculate_previous_runtime("result_fmt-controller")
        print(f"Total previous time: {total_previous_time} seconds")
        print(f"Last completed step: {last_step}")

        remaining_time = MAX_RUNTIME - total_previous_time
        print(f"Remaining time: {remaining_time} seconds")
        start_step = last_step + 1

    fuzzer = Fuzzer(fmt_firmware_base, adapter, config=config, verbose=True)
    fuzzer.initial_analyze(target_thread_functions, "initial_analyze_fmt")

    # Set the starting step number
    fuzzer.steps_count = start_step

    start_program = time.time()

    while True:
        if time.time() - start_program > remaining_time:
            print(f"Remaining time ({remaining_time} seconds) has elapsed. Program will exit.")
            break

        start_time = time.time()
        fuzzer.fuzz(methods=["sat-validate"])
        end_time = time.time()
        print(f"Time taken: {end_time - start_time} seconds")

        fuzzer.mutate(target_thread_functions, methods=["sat-validate"])


if __name__ == "__main__":
    main()
