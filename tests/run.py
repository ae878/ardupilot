import sys
import os
import json
import time
import glob
import argparse
from typing import Tuple

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from src.adapter.fmt_controller.fmt_controller import FMTControllerAdapter
from src.adapter.librepilot.librepilot import LibrepilotAdapter
from src.adapter.dronin.dronin import DroninAdapter
from src.adapter.px4.px4 import PX4Adapter
from src.adapter.ardupilot.ardupilot import ArdupilotAdapter
from src.adapter.striso.striso import StrisoAdapter
from src.adapter.taulabs.taulabs import TaulabsAdapter
from src.adapter.wideband.wideband import WidebandAdapter
from src.config.config import ConfigFactory
from src.config.conditional_config import Condition
from src.fuzzer import Fuzzer
from utils.utils import calculate_previous_runtime

base_configuration = {
    "ardupilot": {
        "base": "/home/ubuntu/lab/ardupilot",
        "build_base": "/home/ubuntu/lab/ardupilot/build/R9Pilot",
        "thread_functions_file_path": "src/adapter/ardupilot/thread_functions.json",
        "condition_json_path": "src/adapter/ardupilot/condition_analysis_result.json",
        "macros_json_path": "src/adapter/ardupilot/macros.json",
        "build_commands_json_path": "src/adapter/ardupilot/build_commands.json",
        "result_file_name": "result_ardupilot",
    },
    "dronin": {
        "base": "/home/ubuntu/lab/dRonin",
        "build_base": "/home/ubuntu/lab/dRonin/build",
        "thread_functions_file_path": "src/adapter/dronin/thread_functions.json",
        "condition_json_path": "src/adapter/dronin/condition_analysis_result.json",
        "macros_json_path": "src/adapter/dronin/macros.json",
        "build_commands_json_path": None,
        "result_file_name": "result_dronin",
    },
    "fmt-firmware": {
        "base": "/home/ubuntu/lab/FMT-Firmware",
        "build_base": "/home/ubuntu/lab/FMT-Firmware/target/amov/icf5/build",
        "thread_functions_file_path": "src/adapter/fmt_controller/thread_functions.json",
        "condition_json_path": "src/adapter/fmt_controller/condition_analysis_result.json",
        "macros_json_path": "src/adapter/fmt_controller/macros.json",
        "build_commands_json_path": None,
        "result_file_name": "result_fmt-controller",
    },
    "librepilot": {
        "base": "/home/ubuntu/lab/librepilot",
        "build_base": "/home/ubuntu/lab/librepilot/build",
        "thread_functions_file_path": "src/adapter/librepilot/thread_functions.json",
        "condition_json_path": "src/adapter/librepilot/condition_analysis_result.json",
        "macros_json_path": "src/adapter/librepilot/macros.json",
        "build_commands_json_path": None,
        "result_file_name": "result_librepilot",
    },
    "px4": {
        "base": "/home/ubuntu/lab/PX4-Autopilot",
        "build_base": "/home/ubuntu/lab/PX4-Autopilot/build",
        "thread_functions_file_path": "src/adapter/px4/thread_functions.json",
        "condition_json_path": "src/adapter/px4/condition_analysis_result.json",
        "macros_json_path": "src/adapter/px4/macros.json",
        "build_commands_json_path": None,
        "result_file_name": "result_px4",
    },
    "striso": {
        "base": "/home/ubuntu/lab/striso-control-firmware",
        "build_base": "/home/ubuntu/lab/striso-control-firmware/build",
        "thread_functions_file_path": "src/adapter/striso/thread_functions.json",
        "condition_json_path": "src/adapter/striso/condition_analysis_result.json",
        "macros_json_path": "src/adapter/striso/macros.json",
        "build_commands_json_path": None,
        "result_file_name": "result_striso",
    },
    "taulabs": {
        "base": "/home/ubuntu/lab/TauLabs",
        "build_base": "/home/ubuntu/lab/TauLabs/build",
        "thread_functions_file_path": "src/adapter/taulabs/thread_functions.json",
        "condition_json_path": "src/adapter/taulabs/condition_analysis_result.json",
        "macros_json_path": "src/adapter/taulabs/macros.json",
        "build_commands_json_path": None,
        "result_file_name": "result_taulabs",
    },
    "wideband": {
        "base": "/home/ubuntu/lab/wideband/firmware",
        "build_base": "/home/ubuntu/lab/wideband/firmware/build",
        "thread_functions_file_path": "src/adapter/wideband/thread_functions.json",
        "condition_json_path": "src/adapter/wideband/condition_analysis_result.json",
        "macros_json_path": "src/adapter/wideband/macros.json",
        "build_commands_json_path": None,
        "result_file_name": "result_wideband",
    },
}


def main():
    parser = argparse.ArgumentParser(description="Run FMT firmware fuzzer")
    parser.add_argument(
        "-c", "--continue-status", action="store_true", help="Resume from last completed step and adjust runtime"
    )
    parser.add_argument("-t", "--target", type=str, help="Target project to run")
    parser.add_argument("-s", "--use-sat", action="store_true", help="Use SAT to fuzz")
    parser.add_argument("-r", "--use-related", action="store_true", help="Use related to fuzz")
    args = parser.parse_args()

    target = args.target
    use_sat = args.use_sat
    use_related = args.use_related

    use_continue = args.continue_status

    if target not in base_configuration:
        raise ValueError(f"Invalid target: {target}")

    target_config = base_configuration[args.target]
    firmware_base = target_config["base"]
    firmware_build_base = target_config["build_base"]
    thread_functions_file_path = target_config["thread_functions_file_path"]
    condition_json_path = target_config["condition_json_path"]
    macros_json_path = target_config["macros_json_path"]
    build_commands_json_path = target_config["build_commands_json_path"]
    result_file_name = target_config["result_file_name"]

    target_thread_functions = []
    with open(thread_functions_file_path, "r") as f:
        datas = json.load(f)
        for data in datas:
            target_thread_functions.append(data["thread"])

    if len(target_thread_functions) == 0:
        raise ValueError("No thread functions found")

    # Set config file path for creating config.h
    config = None
    if use_sat:
        condition = Condition(condition_json_path)
        config = ConfigFactory(macros_json_path, condition=condition)
    else:
        config = ConfigFactory(macros_json_path)

    build_commands = []
    if build_commands_json_path:
        with open(build_commands_json_path, "r") as f:
            build_commands = json.load(f)

    adapter = None
    # For optimize, we create adapter class in here
    if target == "ardupilot":
        adapter = ArdupilotAdapter(
            firmware_base,
            build_commands,
            thread_functions_file_path=thread_functions_file_path,
            verbose=True,
            build_base=firmware_build_base,
        )
    elif target == "dronin":
        adapter = DroninAdapter(
            firmware_base,
            build_commands,
            thread_functions_file_path=thread_functions_file_path,
            verbose=True,
            build_base=firmware_build_base,
        )
    elif target == "fmt-firmware":
        adapter = FMTControllerAdapter(
            firmware_base,
            build_commands,
            thread_functions_file_path=thread_functions_file_path,
            verbose=True,
            build_base=firmware_build_base,
        )
    elif target == "librepilot":
        adapter = LibrepilotAdapter(
            firmware_base,
            build_commands,
            thread_functions_file_path=thread_functions_file_path,
            verbose=True,
            build_base=firmware_build_base,
        )
    elif target == "px4":
        adapter = PX4Adapter(
            firmware_base,
            build_commands,
            thread_functions_file_path=thread_functions_file_path,
            verbose=True,
            build_base=firmware_build_base,
        )
    elif target == "striso":
        adapter = StrisoAdapter(
            firmware_base,
            build_commands,
            thread_functions_file_path=thread_functions_file_path,
            verbose=True,
        )
    elif target == "taulabs":
        adapter = TaulabsAdapter(
            firmware_base,
            build_commands,
            thread_functions_file_path=thread_functions_file_path,
            verbose=True,
        )
    elif target == "wideband":
        adapter = WidebandAdapter(
            firmware_base,
            build_commands,
            thread_functions_file_path=thread_functions_file_path,
            verbose=True,
        )
    else:
        raise ValueError(f"Invalid target: {target}")
    # Initialize runtime variables
    MAX_RUNTIME = 86400  # 24 hours in seconds
    remaining_time = MAX_RUNTIME
    start_step = 0

    # If resume flag is set, calculate previous runtime and adjust start step
    if use_continue:
        print(f"[+] Resuming from last completed step")
        total_previous_time, last_step = calculate_previous_runtime(result_file_name)
        print(f"[+] Total previous time: {total_previous_time} seconds")
        print(f"[+] Last completed step: {last_step}")

        remaining_time = MAX_RUNTIME - total_previous_time
        print(f"[+] Remaining time: {remaining_time} seconds")
        start_step = last_step + 1
    print(f"[+] Target: {target}\tUse related: {use_related}\tUse sat: {use_sat}")
    input("[-] Press Enter to continue...")
    fuzzer = Fuzzer(firmware_base, adapter, config=config, verbose=True)
    if use_related:
        fuzzer.initial_analyze(target_thread_functions, "initial_analyze_fmt")

    # Set the starting step number
    fuzzer.steps_count = start_step

    start_program = time.time()

    mutate_methods = []
    if use_sat:
        mutate_methods.append("sat-validate")
    if use_related:
        mutate_methods.append("related")

    while True:
        if time.time() - start_program > remaining_time:
            print(f"[+] Remaining time ({remaining_time} seconds) has elapsed. Program will exit.")
            break

        start_time = time.time()
        if use_related:
            fuzzer.fuzz(methods=["related-validate"])
        else:
            fuzzer.fuzz(methods=[])
        end_time = time.time()
        print(f"[+] Time taken: {end_time - start_time} seconds")

        fuzzer.mutate(target_thread_functions, methods=mutate_methods)


if __name__ == "__main__":
    main()
