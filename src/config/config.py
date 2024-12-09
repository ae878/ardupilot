import json
import os
import random

class ConfigFactory:
    def __init__(self, config_json_file: str):
        self.config_json_file = config_json_file
        self.config: list[dict] = self.load_config()

    def get_config(self, key) -> dict:
        """
        {
            "macro": "BOARD",
            "type": "string",
            "value": "f0_module",
            "value_candidate": ["f0_module", "f1_common", "f1_dual", "f1_dual_rev1", "f1_rev2", "f1_rev3"]
        }
        """
        for item in self.config:
            if item["macro"] == key:
                return item
        # Todo: change custom exception
        raise Exception(f"Key {key} not found in config")

    def load_config(self):
        '''
            Config file looks like:
            [
                {
                    "macro": "AP_SCRIPTING_ENABLED",
                    "value": "0"
                },
                {
                    "macro": "LWIP_ALTCP",
                    "value": "0"
                },
                ...
            ]
        '''
        with open(self.config_json_file, "r") as file:
            return json.load(file)

    def flip_config(self, macro_name: str):
        for item in self.config:
            if item["macro"] == macro_name:
                item["value"] = "1" if item["value"] == "0" else "0"
                return
            
    def change_config(self, macro_name: str):
        for item in self.config:
            if item["macro"] == macro_name:
                if item.get("value_candidate"):
                    item["value"] = random.choice(item["value_candidate"])
                return
    
    def random_select_config(self):
        random_index = random.randint(0, len(self.config) - 1)
        return self.config[random_index]

    def create_config_header(self, dst="config.h") -> str:
        # path not exist, create dir
        try:
            if not os.path.exists(os.path.dirname(dst)):
                os.makedirs(os.path.dirname(dst), exist_ok=True)
        except Exception as e:
            pass
        with open(dst, "w") as file:
            for item in self.config:
                macro = item["macro"]
                value = item["value"]
                file.write(f"#define {macro} {value}\n")

        return os.path.abspath(dst)
