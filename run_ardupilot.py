from src.adapter.ardupilot.ardupilot import ArdupilotAdapter
from src.config.config import ConfigFactory
from src.config.conditional_config import Condition
from src.fuzzer import Fuzzer
import json
import time

ardupilot_base = "/home/ubuntu/lab/ardupilot/build/R9Pilot"
thread_functions_file_path = "src/adapter/ardupilot/thread_functions.json"


condition = Condition("src/adapter/ardupilot/condition_analysis_result.json")
print(condition)
# Set config file path for creating config.h
config1 = ConfigFactory("src/adapter/ardupilot/macros.json", condition=condition)
with open("src/adapter/ardupilot/build_commands.json", "r") as f:
    build_commands = json.load(f)

adapter = ArdupilotAdapter(
    ardupilot_base, build_commands, thread_functions_file_path=thread_functions_file_path, verbose=True
)


fuzzer = Fuzzer(ardupilot_base, adapter, config=config1, verbose=True)
fuzzer.initial_analyze("AP_InertialSensor_ADIS1647x::loop", initial_analyze_result_dir="initial_analyze_ardupilot")
# with open("fuzzer.json", "w") as f:
#     json.dump(list(fuzzer.related_files_per_function["task_mavobc_entry"]), f)

# fuzzer.change_config_with_seed(config2)
while True:

    start_time = time.time()
    fuzzer.fuzz()
    end_time = time.time()
    print(f"Time taken: {end_time - start_time} seconds")

    input("Press Enter to continue...")
    fuzzer.mutate("AP_InertialSensor_ADIS1647x::loop", methods=["related", "stack"])
