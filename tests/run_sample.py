from src.adapter.sample.sample import SampleAdapter
from src.config.config import ConfigFactory
from src.fuzzer import Fuzzer
import json
import time

sample_base = "/home/ubuntu/conffuzz/sample"
thread_functions_file_path = "src/adapter/sample/thread_functions.json"

# Set config file path for creating config.h
config = ConfigFactory("src/adapter/sample/macros.json")
# header_file = config.create_config_header()


build_commands = []
adapter = SampleAdapter(
    sample_base, build_commands, thread_functions_file_path=thread_functions_file_path, verbose=True
)


fuzzer = Fuzzer(sample_base, "src/adapter/sample/macros.json", adapter, verbose=True)
adapter.build(config)
fuzzer.initial_analyze("sample_function")
# with open("fuzzer.json", "w") as f:
#     json.dump(list(fuzzer.related_files_per_function["task_mavobc_entry"]), f)
while True:
    start_time = time.time()
    fuzzer.fuzz()
    end_time = time.time()
    print(f"Time taken: {end_time - start_time} seconds")

    input("Press Enter to continue...")
    fuzzer.mutate("sample_function", methods=["related", "stack"])
