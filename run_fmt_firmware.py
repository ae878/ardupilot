from src.adapter.fmt_controller.fmt_controller import FMTControllerAdapter
from src.config.config import ConfigFactory
from src.fuzzer import Fuzzer
import json

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
while True:
    fuzzer.fuzz()
    fuzzer.mutate("task_mavobc_entry")
