from src.adapter.fmt_controller.fmt_controller import FMTControllerAdapter
from src.config.config import ConfigFactory
from src.fuzzer import Fuzzer
import time

fmt_firmware_base = "/home/ubuntu/lab/FMT-Firmware"
fmt_firmware_build_base = "/home/ubuntu/lab/FMT-Firmware/target/amov/icf5/build"
thread_functions_file_path = "src/adapter/fmt_controller/thread_functions.json"

# Set config file path for creating config.h
config = ConfigFactory("src/adapter/fmt_controller/macros.json")

build_commands = []
adapter = FMTControllerAdapter(
    fmt_firmware_base,
    build_commands,
    thread_functions_file_path=thread_functions_file_path,
    verbose=True,
    build_base=fmt_firmware_build_base,
)


fuzzer = Fuzzer(fmt_firmware_base, adapter, config=config, verbose=True)
# fuzzer.initial_analyze("task_mavobc_entry")
while True:
    start_time = time.time()
    fuzzer.fuzz()
    end_time = time.time()
    print(f"Time taken: {end_time - start_time} seconds")

    input(
        "Press Enter to continue...",
    )
    fuzzer.mutate("task_mavobc_entry", methods=[])
