from src.config.config import ConfigFactory
from src.adapter.ardupilot.ardupilot import ArdupilotAdapter
from src.fuzzer import Fuzzer
import json

ardupilot_base = "/home/ubuntu/ardupilot/build/AnyleafH7"
thread_functions_file_path = "src/adapter/ardupilot/thread_functions.json"

# Set config file path for creating config.h
config = ConfigFactory("src/adapter/ardupilot/macros.json")
header_file = config.create_config_header()


json_datas = []
with open("/home/ubuntu/ardupilot/build/AnyleafH7/compile_commands.json", "r") as file:
    json_datas = json.load(file)

build_commands = []

for data in json_datas:
    build_commands.append(data["arguments"])
adapter = ArdupilotAdapter(ardupilot_base, build_commands,
                           thread_functions_file_path=thread_functions_file_path,
                           verbose=True)


fuzzer = Fuzzer(ardupilot_base, "src/adapter/ardupilot/macros.json", adapter, verbose=True)
while True:
    fuzzer.fuzz()
    fuzzer.mutate("AP_OSD::osd_thread")