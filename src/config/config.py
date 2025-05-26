import json
import os
import random
import logging as lg
from typing import Union, List, Dict, Optional
from src.config.conditional_config import Condition
from src.utils.logging import get_logger
from src.config.configblock import ConfigBlock
from src.config.configblockstructure import ConfigBlockStructure

logger = get_logger(__name__)


class Config:
    def __init__(self, config: dict):
        # define 매크로 명
        # name of #define
        self.name: str = config.get("name", "")
        # 매크로 타입 (hex, int, str, ..)
        # type of #define
        self.type: str = config.get("type", "")
        # 매크로 기본 값
        # default value of #define
        self.value: Union[str, int, float] = config.get("value", "")
        # 매크로 값이 될 수 있는 값들
        # value candidates of #define
        self.value_candidates: List[Union[str, int, float]] = config.get(
            "value_candidates", []
        )
        # 매크로가 정의된 파일들 list
        # files that #define is defined in
        self.defined_in: List[str] = config.get("defined_in", [])
        # 매크로가 사용된 파일들 list
        # files that #define is used in users
        self.used_in: List[str] = config.get("used_in", [])
        # 매크로가 사용된 함수들 dict
        # functions that #define is used in
        self.used_in_functions: Dict[str, List[str]] = config.get(
            "used_in_functions", {}
        )

        # 매크로가 사용된 범위들
        # scopes that #define is used in
        self.conditional_scopes: List[ConfigBlock] = []

        # The child/parent of the config (dependent between nodes)
        self.child_configs: List[Config] = config.get("child_configs", [])
        self.parent_configs: List[Config] = config.get("parent_configs", [])

        for conditional_scope in config.get("conditional_scopes", []):
            self.conditional_scopes.append(ConfigBlock(conditional_scope))

    def __json__(self):
        return {
            "name": self.name,
            "type": self.type,
            "value": self.value,
            "value_candidates": self.value_candidates,
            "defined_in": self.defined_in,
            "used_in": self.used_in,
            "used_in_functions": self.used_in_functions,
            "conditional_scopes": [
                scope.__json__() for scope in self.conditional_scopes
            ],
            "child_configs": [child.__json__() for child in self.child_configs],
            "parent_configs": [parent.__json__() for parent in self.parent_configs],
        }

    def solve_condition(self, condition_line: str) -> list:
        """
        Parse condition line and return valid value candidates

        Args:
            condition_line (str): Condition line like "#if RT_THREAD_PRIORITY_MAX > 32"

        Returns:
            list: List of valid value candidates that satisfy the condition
        """
        # Remove comments if exists
        if "/*" in condition_line:
            condition_line = condition_line[: condition_line.index("/*")].strip()

        # Remove #if or #ifdef
        condition = condition_line.replace("#if", "").replace("#ifdef", "").strip()

        # Remove parentheses
        condition = condition.replace("(", "").replace(")", "").strip()

        # Handle simple defined check (e.g. #if MAVLINK_COMMAND_24BIT)
        if " " not in condition:
            # For boolean configs, return [1] as it needs to be defined/true
            return [1]

        # Handle multiple conditions with && or ||
        if "&&" in condition or "||" in condition:
            # For now, we'll just handle the first condition
            condition = condition.split("&&")[0].split("||")[0].strip()

        # Parse comparison
        try:
            # Split by spaces and filter out empty strings
            parts = [p.strip() for p in condition.split() if p.strip()]

            if len(parts) != 3:  # Must have var, operator, value
                return []

            var_name, operator, value = parts
            value = float(value)  # Convert to number

            # Get current config's value candidates
            candidates = self.value_candidates

            # Filter based on operator
            if operator == ">":
                return [c for c in candidates if float(c) > value]
            elif operator == ">=":
                return [c for c in candidates if float(c) >= value]
            elif operator == "<":
                return [c for c in candidates if float(c) < value]
            elif operator == "<=":
                return [c for c in candidates if float(c) <= value]
            elif operator == "==":
                return [c for c in candidates if float(c) == value]
            elif operator == "!=":
                return [c for c in candidates if float(c) != value]

        except (ValueError, IndexError):
            # If parsing fails, return empty list
            return []

        return []


    def select_block(self, min_executable_line: int) -> list[str]:
        """
        입력: 최소 실행가능한 라인
        출력: SMT로 풀수있는 식 리스트
        """

class ConfigFactory:
    def __init__(
        self,
        config_json_file: str,
        condition: Union[Condition, None] = None,
        condition_threshold: float = 0.12,
    ):
        """
        self.config: dict[str, Config] = [Config Name]: [Config]
        """
        self.config_json_file = os.path.abspath(config_json_file)
        self.config: dict[str, Config] = self.load_config()
        self.condition: Union[Condition, None] = condition
        self.condition_threshold: float = condition_threshold

    def get_config(self, key) -> Config:
        try:
            return self.config[key]
        except KeyError:
            # Todo: change custom exception
            raise Exception(f"Key {key} not found in config")

    def load_config(self) -> dict[str, Config]:
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

    def change_config(self, macro_name: str, value: Union[str, int, float] = None):
        """
        매크로의 값을 변경하는 함수입니다.

        Args:
            macro_name (str): 변경할 매크로의 이름
            value (Union[str, int, float], optional): 변경할 값. None인 경우 value_candidates에서 랜덤하게 선택됩니다.

        Raises:
            NotImplementedError: config가 list 타입일 경우 발생
        """
        if isinstance(self.config, list):
            raise NotImplementedError("Not implemented")

        # config의 모든 item을 순회
        for item in self.config.values():
            # item이 dict 타입인 경우
            if isinstance(item, dict):
                if item["name"] == macro_name:
                    if item.get("value_candidates"):
                        if value:
                            item["value"] = value  # 지정된 값으로 변경
                        else:
                            item["value"] = random.choice(
                                item["value_candidates"]
                            )  # 랜덤 값으로 변경
                    return

            # item이 Config 타입인 경우
            if isinstance(item, Config):
                if item.name == macro_name:
                    if item.value_candidates:
                        if value:
                            item.value = value  # 지정된 값으로 변경
                        else:
                            item.value = random.choice(
                                item.value_candidates
                            )  # 랜덤 값으로 변경
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

    def set_config_to_highest_stack(self):

        for config in self.config.values():
            name = config.name
            tmp_value = config.value
            max_scope_size = -1

            # 모든 Conditional_scope를 찾으면서, 커버하는 scope_size가 큰 경우
            # 그와 valid한 value를 찾아 그걸 set함
            for conditional_scope in config.conditional_scopes:
                if max_scope_size < conditional_scope.get("scope_size", 0):
                    max_scope_size = conditional_scope.get("scope_size", 0)
                    original_condition = conditional_scope.get("original_condition", "")
                    try:
                        valid_value_candidates = config.solve_condition(
                            original_condition
                        )
                        valid_value = random.choice(valid_value_candidates)
                        tmp_value = valid_value
                    except Exception as e:
                        logger.warning(
                            f"[-] Error occurred while solving condition: {e}"
                        )
                        continue

            config.value = tmp_value

            self.config[name] = config
        return

    def validate_configuration(
        self, condition_threshold: float = -1
    ) -> tuple[bool, list[tuple[str, str, str]]]:
        satisfied_count = 0
        non_satisfied_count = 0
        unsatisfied_macros = []
        if condition_threshold == -1:
            condition_threshold = self.condition_threshold

        if not self.condition:
            return True, []

        for macro in self.config.values():
            macro_name = macro.name
            macro_value = macro.value
            if macro_value is None:
                continue
            for condition_item in self.condition.condition_analysis.values():
                if macro_name in condition_item:
                    logger.debug(
                        f"[-] {macro_name} in {condition_item}, {macro_value} in {condition_item.satisfying_values}"
                    )
                    if str(macro_value) == str(
                        condition_item.satisfying_values[macro_name]
                    ):
                        satisfied_count += 1
                    else:
                        non_satisfied_count += 1
                        unsatisfied_macros.append(
                            (
                                macro_name,
                                str(macro_value),
                                str(condition_item.satisfying_values[macro_name]),
                            )
                        )
        if satisfied_count + non_satisfied_count == 0:
            logger.warning("[-] SAT validate failed, No condition analysis result")
            return True, []
        is_satisfied = (
            satisfied_count / (satisfied_count + non_satisfied_count)
            >= self.condition_threshold
        )
        satisfied_percentage = round(
            satisfied_count / (satisfied_count + non_satisfied_count), 2
        )
        logger.info(
            f"[-] SAT validate Percentage: {satisfied_percentage} ({is_satisfied}) ({satisfied_count}/{satisfied_count + non_satisfied_count})"
        )
        return is_satisfied, unsatisfied_macros

    def create_config_header(self, dst="config.h", target_configs: list = []) -> str:
        raise NotImplementedError("Deprecated Function")
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

    def dump_config(self) -> dict:
        data = {}
        for macro in self.config.values():
            data[macro.name] = macro.value
        return data
