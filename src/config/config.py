import json
import os
import random
from typing import Union


class Config:
    def __init__(self, config: dict):
        # define 매크로 명
        self.name: str = config.get("name", "")
        # 매크로 타입 (hex, int, str, ..)
        self.type: str = config.get("type", "")
        # 매크로 기본 값
        self.value: Union[str, int, float] = config.get("value", "")
        # 매크로 값이 될 수 있는 값들
        self.value_candidates: list[Union[str, int, float]] = config.get("value_candidates", [])
        # 매크로가 정의된 파일들 list
        self.defined_in: list[str] = config.get("defined_in", [])
        # 매크로가 사용된 파일들 list
        self.used_in: list[str] = config.get("used_in", [])
        # 매크로가 사용된 함수들 dict
        self.used_in_functions: dict[str, list[str]] = config.get("used_in_functions", {})

        # 매크로가 사용된 범위들
        self.conditional_scopes: list[dict] = config.get("conditional_scopes", [])


class ConfigFactory:
    def __init__(self, config_json_file: str, verbose: bool = False):
        """
        self.config: dict[str, Config] = [Config Name]: [Config]
        """
        self.config_json_file = os.path.abspath(config_json_file)
        self.config: dict[str, Config] = self.load_config()

    def get_config(self, key) -> Config:
        try:
            return self.config[key]
        except KeyError:
            # Todo: change custom exception
            raise Exception(f"Key {key} not found in config")

    def load_config(self) -> dict[str, Config]:

        print(self.config_json_file)
        print("================")
        data = {}
        with open(self.config_json_file, "r") as file:
            data = json.load(file)

        for key, value in data.items():
            data[key] = Config(value)

        self.config = data
        return self.config

    def flip_config(self, macro_name: str) -> dict:
        macro = self.get_config(macro_name)
        macro["value"] = "1" if macro["value"] == "0" else "0"
        return macro

    def change_config(self, macro_name: str):
        if isinstance(self.config, list):
            raise NotImplementedError("Not implemented")
        for item in self.config.values():
            if isinstance(item, dict):
                if item["name"] == macro_name:
                    if item.get("value_candidates"):
                        item["value"] = random.choice(item["value_candidates"])
                    return
            if isinstance(item, Config):
                if item.name == macro_name:
                    if item.value_candidates:
                        item.value = random.choice(item.value_candidates)
                    return

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
        print(target_configs)
        try:
            if not os.path.exists(os.path.dirname(dst)):
                os.makedirs(os.path.dirname(dst), exist_ok=True)
        except Exception as e:
            pass
        with open(dst, "w") as file:
            if isinstance(self.config, dict):
                for item in self.config.keys():
                    if isinstance(item, dict):
                        raise NotImplementedError("Not implemented")
                    elif isinstance(item, str):

                        dict_item = self.config.get(item)
                        if not dict_item:
                            continue
                        macro = dict_item.name
                        value = dict_item.value
                        # Process exception
                        if isinstance(value, str) and "#ifdef" in value:
                            continue

                        if len(target_configs) > 0 and macro not in target_configs:
                            continue
                        # file.write(f"#ifdef {macro}\n")
                        file.write(f"#undef {macro}\n")
                        # file.write(f"#endif\n")
                        file.write(f"#define {macro} {value}\n")
        return os.path.abspath(dst)
