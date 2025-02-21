from src.adapter.ardupilot.ardupilot import ArdupilotAdapter
from src.config.config import ConfigFactory
from src.fuzzer import Fuzzer
import json
import time

ardupilot_base = "/home/ubuntu/lab/ardupilot/build/R9Pilot"
thread_functions_file_path = "src/adapter/ardupilot/thread_functions.json"

# Set config file path for creating config.h
config = ConfigFactory("src/adapter/ardupilot/macros.json")
# header_file = config.create_config_header()

with open("src/adapter/ardupilot/build_commands.json", "r") as f:
    build_commands = json.load(f)

adapter = ArdupilotAdapter(
    ardupilot_base, build_commands, thread_functions_file_path=thread_functions_file_path, verbose=True
)


fuzzer = Fuzzer(ardupilot_base, "src/adapter/ardupilot/macros.json", adapter, verbose=True)
fuzzer.initial_analyze("AP_InertialSensor_ADIS1647x::loop", initial_analyze_result_dir="initial_analyze_ardupilot")
# with open("fuzzer.json", "w") as f:
#     json.dump(list(fuzzer.related_files_per_function["task_mavobc_entry"]), f)
while True:
    start_time = time.time()
    fuzzer.fuzz()
    end_time = time.time()
    print(f"Time taken: {end_time - start_time} seconds")

    input("Press Enter to continue...")
    fuzzer.mutate("AP_InertialSensor_ADIS1647x::loop", methods=["related", "stack"])
