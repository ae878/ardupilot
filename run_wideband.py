from adapter.wideband.wideband import WidebandAdapter
from src.config.config import ConfigFactory
from src.adapter.ardupilot.ardupilot import ArdupilotAdapter
from src.fuzzer import Fuzzer
import json

wideband_base = "/home/ubuntu/ardupilot/build/AnyleafH7"
thread_functions_file_path = "src/adapter/ardupilot/thread_functions.json"

# Set config file path for creating config.h
config = ConfigFactory("src/adapter/wideband/macros.json")
header_file = config.create_config_header()


build_commands = []
adapter = WidebandAdapter(wideband_base, build_commands,
                           thread_functions_file_path=thread_functions_file_path,
                           verbose=True)


fuzzer = Fuzzer(wideband_base, "src/adapter/wideband", adapter, verbose=True)
while True:
    fuzzer.fuzz()
    fuzzer.mutate("AuxOutThread")