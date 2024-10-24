import json
import os


class ConfigFactory:
    def __init__(self, config_json_file: str):
        self.config_json_file = config_json_file
        self.config = self.load_config()

    def get_config(self, key):
        return self.config[key]

    def load_config(self):
        with open(self.config_json_file, "r") as file:
            return json.load(file)

    def create_config_header(self, dst="config.h") -> str:
        with open(dst, "w") as file:
            for item in self.config:
                macro = item["macro"]
                value = item["value"]
                file.write(f"#define {macro} {value}\n")

        return os.path.abspath(dst)
