from config.config import ConfigFactory
from adapter.ardupilot.ardupilot import ArdupilotAdapter
import json

ardupilot_base = "/home/ubuntu/ardupilot/build/CUAV-Nora"
config = ConfigFactory("adapter/macros.json")
header_file = config.create_config_header()


json_datas = []
with open("/home/ubuntu/ardupilot/build/CUAV-Nora/compile_commands.json", "r") as file:
    json_datas = json.load(file)

build_commands = []

for data in json_datas:
    build_commands.append(data["arguments"])
adapter = ArdupilotAdapter(ardupilot_base, build_commands, header_file)
adapter.build()
adapter.analyze()
adapter.dump_result()
