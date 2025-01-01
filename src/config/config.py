import json
import os
import random
from typing import Union


class ConfigFactory:
    def __init__(self, config_json_file: str, verbose: bool = False):
        self.config_json_file = os.path.abspath(config_json_file)
        self.config: Union[dict[str, dict], list[dict]] = self.load_config()

    def get_config(self, key) -> dict:
        """
        {
            "macro": "BOARD",
            "type": "string",
            "value": "f0_module",
            "value_candidates": ["f0_module", "f1_common", "f1_dual", "f1_dual_rev1", "f1_rev2", "f1_rev3"]
        }
        """
        try:
            return self.config[key]
        except KeyError:
            # Todo: change custom exception
            raise Exception(f"Key {key} not found in config")

    def load_config(self):
        """
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
        """

        print(self.config_json_file)
        print("================")
        with open(self.config_json_file, "r") as file:
            return json.load(file)

    def flip_config(self, macro_name: str) -> dict:
        macro = self.get_config(macro_name)
        macro["value"] = "1" if macro["value"] == "0" else "0"
        return macro

    def change_config(self, macro_name: str):
        for item in self.config:
            if isinstance(item, dict):
                if item["macro"] == macro_name:
                    if item.get("value_candidates"):
                        item["value"] = random.choice(item["value_candidates"])
                    return
            elif isinstance(item, str):
                raise NotImplementedError("Not implemented")
                item = self.get_config(item)

    def random_select_config(self):
        if isinstance(self.config, list):
            random_item = random.randint(0, len(self.config) - 1)
            return self.config[random_item]
        elif isinstance(self.config, dict):
            random_item = random.choice(list(self.config.keys()))
            return self.config[random_item]
        else:
            raise Exception("Invalid config type")

    def create_config_header(self, dst="config.h", target_configs: list = []) -> str:
        # path not exist, create dir
        try:
            if not os.path.exists(os.path.dirname(dst)):
                os.makedirs(os.path.dirname(dst), exist_ok=True)
        except Exception as e:
            pass
        with open(dst, "w") as file:
            if isinstance(self.config, dict):
                for item in self.config.keys():
                    if isinstance(item, dict):
                        macro = item["macro"]
                        value = item["value"]
                        if len(target_configs) > 0 and macro not in target_configs:
                            continue
                        file.write(f"#define {macro} {value}\n")
                    elif isinstance(item, str):
                        dict_item = self.config.get(item)
                        macro = item
                        value = dict_item.get("value")
                        if len(target_configs) > 0 and macro not in target_configs:
                            continue
                        # file.write(f"#ifdef {macro}\n")
                        file.write(f"#undef {macro}\n")
                        # file.write(f"#endif\n")
                        file.write(f"#define {macro} {value}\n")
        return os.path.abspath(dst)
