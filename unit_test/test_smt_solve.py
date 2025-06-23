import json
import os
import sys
import argparse
import random

sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from src.config.z3_config_solver import Z3ConfigSolver

macro_path = "unit_test/assets/ardupilot_macros.json"
equation_path = "unit_test/assets/test_z3_equations.json"
with open(equation_path, "r") as f:
    equations = json.load(f)
with open(macro_path, "r") as f:
    macros = json.load(f)


if __name__ == "__main__":
    # parser = argparse.ArgumentParser(description="Test SMT selection")
    # parser.add_argument("-f", "--fuzz", action="store_true", help="Fuzz test with random condition")
    # args = parser.parse_args()

    z3_solver = Z3ConfigSolver(macro_path)
    # sample_config = config_factory.get_config("ENABLE_LOAD_TEST")
    # print(str(sample_config))
    # print(sample_config.select_block(0))
    solution = z3_solver.solve("s4", equations)
