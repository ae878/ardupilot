import json
import os
import sys
import argparse
import random

sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from src.config.config import ConfigFactory
from src.config.conditional_config import Condition
from src.config.z3_config_solver import Z3ConfigSolver

macros = {}
conditional_analysis = {}
print(os.path.abspath("assets/fmt_macros.json"))

with open("unit_test/assets/fmt_macros.json", "r") as f:
    macros = json.load(f)

with open("unit_test/assets/fmt_condition_analysis_result.json", "r") as f:
    conditional_analysis = json.load(f)


def get_random_condition():
    # Get all conditions from all files
    all_conditions = []
    for macro in macros.values():
        conditional_scopes = macro.get("conditional_scopes", [])
        if len(conditional_scopes) > 0:
            random_condition_scope = random.choice(conditional_scopes)
            original_condition = random_condition_scope.get("original_condition", "")
            if original_condition:
                all_conditions.append(original_condition)

    return all_conditions


fmt_macros = "unit_test/assets/fmt_macros.json"
ardupilot_macros = "unit_test/assets/ardupilot_macros.json"

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Test Z3 config solver")
    parser.add_argument("-f", "--fuzz", action="store_true", help="Fuzz test with random condition")
    args = parser.parse_args()

    # condition = Condition(conditional_analysis)
    config_factory = ConfigFactory(ardupilot_macros)
    z3_config_solver = Z3ConfigSolver(config_factory)

    if args.fuzz:
        random_conditions = get_random_condition()
        print(random_conditions)
        input()
        if random_conditions:
            print(f"Testing random condition: {random_conditions}")
            print(z3_config_solver.validate_current_values(random_conditions))
        else:
            print("No conditions found in the analysis result")
    else:
        print(
            z3_config_solver.validate_current_values(
                [
                    "#if RT_THREAD_PRIORITY_MAX > 32",
                    "#ifndef IDLE_THREAD_STACK_SIZE",
                    "#if (LWIP_TCP && TCP_LISTEN_BACKLOG && (TCP_DEFAULT_LISTEN_BACKLOG < 0) || (TCP_DEFAULT_LISTEN_BACKLOG > 0xff))",
                ]
            )
        )
