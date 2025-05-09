from z3 import Solver, Int, Bool, And, Or, Not
from typing import Dict, Union, List, Tuple
import logging as lg

from src.config.config import ConfigFactory
from src.utils.logging import get_logger


class Z3ConfigSolver:
    def __init__(self, config_factory: ConfigFactory):
        self.solver = Solver()
        self.config_factory = config_factory
        self.macro_vars: Dict[str, Union[Int, Bool]] = {}
        self.logger = get_logger(__name__, level=lg.DEBUG)
        self._init_macro_variables()
        self._add_value_candidates_constraints()

    def _init_macro_variables(self):
        """Initialize Z3 variables for each macro in the config"""
        for macro_name, config in self.config_factory.config.items():
            if config.type == "bool":
                self.macro_vars[macro_name] = Bool(macro_name)
            else:
                self.macro_vars[macro_name] = Int(macro_name)

    def _add_value_candidates_constraints(self):
        """Add constraints for value_candidates of each macro"""
        for macro_name, config in self.config_factory.config.items():
            if not config.value_candidates:
                continue

            var = self.macro_vars[macro_name]
            if config.type == "bool":
                # For boolean, just ensure it's either True or False
                self.solver.add(Or(var == True, var == False))
            else:
                # For other types, ensure the value is one of the candidates
                candidates = []
                for candidate in config.value_candidates:
                    if isinstance(candidate, int):
                        candidates.append(candidate)
                    elif isinstance(candidate, float):
                        candidates.append(candidate)
                    elif isinstance(candidate, str) and candidate.startswith("0x"):
                        candidates.append(int(candidate, 16))
                    else:
                        self.logger.warning(f"Unsupported candidate type: {candidate} for macro {macro_name}")

                self.solver.add(Or(*[var == c for c in candidates]))

    def _parse_condition(self, condition: str) -> Union[Bool, Int]:
        """Parse a C preprocessor condition into Z3 expression"""
        # Remove comments and whitespace
        condition = condition.strip()
        if condition.startswith("/*"):
            # condition = condition[: condition.index("/*")].strip()
            return Bool(True)
        # Remove #define lines
        if condition.startswith("#define"):
            self.logger.debug(f"Skipping #define: {condition}")
            return Bool(True)  # Always true for #define

        # Handle preprocessor directives
        if condition.startswith("#ifdef"):
            macro_name = condition[6:].strip()
            self.logger.debug(f"#ifdef condition for macro: {macro_name}")
            # For #ifdef, we always want to work with a boolean
            return Bool(macro_name)
        elif condition.startswith("#ifndef"):
            macro_name = condition[7:].strip()
            self.logger.debug(f"#ifndef condition for macro: {macro_name}")
            # For #ifndef, we always want to work with a boolean
            return Not(Bool(macro_name))
        elif condition.startswith("#if"):
            condition = condition[3:].strip()

        # Handle defined() checks
        if "defined" in condition:
            # Extract macro name from defined() or defined MACRO
            if "(" in condition:
                macro_name = condition[condition.index("(") + 1 : condition.index(")")].strip()
            else:
                macro_name = condition.replace("defined", "").strip()
            self.logger.debug(f"defined() check for macro: {macro_name}")
            # For defined(), we always want to work with a boolean
            return Bool(macro_name)

        # Handle logical operators first, but only if they're not inside parentheses
        if "&&" in condition or "||" in condition:
            # Find the outermost logical operator that's not inside parentheses
            paren_count = 0
            for i, char in enumerate(condition):
                if char == "(":
                    paren_count += 1
                elif char == ")":
                    paren_count -= 1
                elif char == "&" and i + 1 < len(condition) and condition[i + 1] == "&" and paren_count == 0:
                    left = condition[:i].strip()
                    right = condition[i + 2 :].strip()
                    self.logger.debug(f"And condition: {left} && {right}")
                    return And(self._parse_condition(left), self._parse_condition(right))
                elif char == "|" and i + 1 < len(condition) and condition[i + 1] == "|" and paren_count == 0:
                    left = condition[:i].strip()
                    right = condition[i + 2 :].strip()
                    self.logger.debug(f"Or condition: {left} || {right}")
                    return Or(self._parse_condition(left), self._parse_condition(right))

        # Handle basic comparisons
        operators = [">=", "<=", "==", "!=", ">", "<"]
        for op in operators:
            if op in condition:
                # Find the operator that's not inside parentheses
                paren_count = 0
                for i in range(len(condition) - len(op) + 1):
                    if condition[i] == "(":
                        paren_count += 1
                    elif condition[i] == ")":
                        paren_count -= 1
                    elif condition[i : i + len(op)] == op and paren_count == 0:
                        left = condition[:i].strip()
                        right = condition[i + len(op) :].strip()

                        # Remove any trailing parentheses from right side
                        while right.endswith(")"):
                            right = right[:-1].strip()

                        # Get or create Z3 variables
                        left_var = self.macro_vars.get(left, Int(left))

                        # Handle right side value
                        if right.isdigit():
                            right_val = int(right)
                        elif right.startswith("0x"):
                            right_val = int(right, 16)
                        else:
                            right_val = self.macro_vars.get(right, Int(right))

                        self.logger.debug(f"Comparison: {left} {op} {right}")

                        if op == ">=":
                            return left_var >= right_val
                        elif op == "<=":
                            return left_var <= right_val
                        elif op == "==":
                            return left_var == right_val
                        elif op == "!=":
                            return left_var != right_val
                        elif op == ">":
                            return left_var > right_val
                        elif op == "<":
                            return left_var < right_val

        # Handle parentheses
        if condition.startswith("(") and condition.endswith(")"):
            # Remove outer parentheses and parse the inner condition
            inner_condition = condition[1:-1].strip()
            return self._parse_condition(inner_condition)

        # Handle ! operator
        if condition.startswith("!"):
            self.logger.debug(f"Not condition: {condition}")
            var = self._parse_condition(condition[1:].strip())
            # For ! operator, we always want to work with a boolean
            return Not(Bool(str(var)))

        # If it's just a macro name without any operator
        if condition in self.macro_vars:
            self.logger.debug(f"Simple macro check: {condition}")
            # For simple macro check, we always want to work with a boolean
            return Bool(condition)

        self.logger.debug(f"Unsupported condition: {condition}")
        # return Bool(condition)
        return Bool(True)

    def validate_current_values(self, conditions: List[str]) -> Tuple[bool, List[str]]:
        """
        Validate if current macro values satisfy given conditions

        Args:
            conditions (List[str]): List of C preprocessor conditions to validate

        Returns:
            Tuple[bool, List[str]]: (is_valid, list of unsatisfied conditions)
        """
        # Reset solver
        self.solver.reset()

        # Add current values as constraints
        for macro_name, config in self.config_factory.config.items():
            if config.value is None:
                continue

            # self.logger.debug(f"Macro: {macro_name}")
            # self.logger.debug(f"  Type: {config.type}")
            # self.logger.debug(f"  Value: {config.value}")
            # self.logger.debug(f"  Z3 Var Type: {type(self.macro_vars[macro_name])}")

            var = self.macro_vars[macro_name]
            if config.type == "bool":
                value = bool(config.value)
            else:
                try:
                    if isinstance(config.value, str) and config.value.startswith("0x"):
                        value = int(config.value, 16)
                    else:
                        value = int(config.value)
                except ValueError:
                    self.logger.warning(f"Invalid value for macro {macro_name}: {config.value}")
                    continue

            self.logger.debug(f"Adding constraint: {macro_name} == {value}")
            self.solver.add(var == value)

        # Check each condition
        unsatisfied = []
        for condition in conditions:
            self.logger.debug(f"\nChecking condition: {condition}")
            z3_condition = self._parse_condition(condition)
            self.logger.debug(f"Parsed Z3 condition: {z3_condition}")

            self.solver.push()  # Save current state
            self.solver.add(z3_condition)

            result = self.solver.check()
            self.logger.debug(f"Solver check result: {result} (type: {type(result)})")

            if str(result) != "sat":
                unsatisfied.append(condition)
                self.logger.debug(f"Condition not satisfied: {condition}")

            self.solver.pop()  # Restore state

        return len(unsatisfied) == 0, unsatisfied

    def solve_conditions(self, conditions: List[str]) -> Dict[str, Union[int, bool]]:
        """
        Solve multiple C preprocessor conditions using Z3

        Args:
            conditions (List[str]): List of C preprocessor conditions

        Returns:
            Dict[str, Union[int, bool]]: Dictionary of macro values that satisfy all conditions
        """
        # Reset solver
        self.solver.reset()

        # Add value candidates constraints
        self._add_value_candidates_constraints()

        # Parse and add all conditions
        for condition in conditions:
            try:
                z3_condition = self._parse_condition(condition)
                self.solver.add(z3_condition)
            except Exception as e:
                self.logger.warning(f"Error parsing condition: {condition}")
                self.logger.warning(f"Error: {e}")
                raise e

        # Try to solve
        if self.solver.check() == "sat":
            model = self.solver.model()
            result = {}

            # Extract values for each macro
            for macro_name, var in self.macro_vars.items():
                if macro_name in model:
                    val = model[var]
                    if isinstance(val, bool):
                        result[macro_name] = val
                    else:
                        result[macro_name] = val.as_long()

            return result

        return {}

    def solve_conditional_scopes(self) -> Dict[str, Dict[str, Union[int, bool]]]:
        """
        Solve all conditional scopes in the config

        Returns:
            Dict[str, Dict[str, Union[int, bool]]]: Dictionary mapping conditions to their solutions
        """
        results = {}

        for config in self.config_factory.config.values():
            for scope in config.conditional_scopes:
                condition = scope.get("original_condition", "")
                if condition:
                    solution = self.solve_conditions([condition])
                    if solution:
                        results[condition] = solution

        return results
