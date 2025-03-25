from src.adapter.fmt_controller.fmt_controller import FMTControllerAdapter
from src.config.config import ConfigFactory
from src.fuzzer import Fuzzer
import time

fmt_firmware_base = "/home/ubuntu/lab/FMT-Firmware"
thread_functions_file_path = "src/adapter/fmt_controller/thread_functions.json"

# Set config file path for creating config.h
config = ConfigFactory("src/adapter/fmt_controller/macros.json")
# header_file = config.create_config_header()


build_commands = []
adapter = FMTControllerAdapter(
    fmt_firmware_base, build_commands, thread_functions_file_path=thread_functions_file_path, verbose=True
)


fuzzer = Fuzzer(fmt_firmware_base, "src/adapter/fmt_controller/macros.json", adapter, verbose=True)
fuzzer.initial_analyze("task_mavobc_entry")
# with open("fuzzer.json", "w") as f:
#     json.dump(list(fuzzer.related_files_per_function["task_mavobc_entry"]), f)
while True:
    start_time = time.time()
    fuzzer.fuzz()
    end_time = time.time()
    print(f"Time taken: {end_time - start_time} seconds")

    input("Press Enter to continue...")
    fuzzer.mutate("task_mavobc_entry", methods=["related", "stack"])
