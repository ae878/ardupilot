from typing import Union
import json


class Condition:
    def __init__(self, conditional_config: Union[dict, str]):
        if isinstance(conditional_config, str):
            with open(conditional_config, "r", encoding="utf-8") as f:
                conditional_config = json.load(f)

        self.total_unique_conditions: int = conditional_config.get("total_unique_conditions", 0)
        self.condition_analysis: dict[str, ConditionItem] = {}

        condition_analysis = conditional_config
        if conditional_config.get("condition_analysis"):
            condition_analysis = conditional_config.get("condition_analysis")

        for expression, condition in condition_analysis.items():
            self.condition_analysis[expression] = ConditionItem(expression, condition)

    def __str__(self):
        return f"Condition <Total Unique Conditions: {self.total_unique_conditions}>"


class ConditionItem:
    def __init__(self, expression: str, condition: dict):
        self.expression = expression
        self.satisfying_values: dict[str, Union[bool, int, str, float]] = condition.get("satisfying_values", {})
        self.conflicting_values: dict[str, Union[bool, int, str, float]] = condition.get("conflicting_values", {})
        self.listed_macros = set()

        for macro in self.satisfying_values.keys():
            self.listed_macros.add(macro)

        for macro in self.conflicting_values.keys():
            self.listed_macros.add(macro)

    def __str__(self):
        return self.expression
