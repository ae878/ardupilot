from z3 import Solver, Int, Bool, And, Or, Not, Implies, BoolSort, is_true
from typing import Dict, Union, List, Tuple
import logging as lg
import json
import os
from datetime import datetime

from src.config.config import ConfigFactory
from src.utils.logging import get_logger


class Z3ConfigValidator:
    """
    특정 configuration 세팅이랑
    특정 SMT 식이 있을때
    해당 configuration 이 식에 대해서 validate 한지 검사함
    """

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
                            # Remove UL suffix if present
                            right = right.replace("U", "").replace("L", "")
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

    def _nested_config_solve_s1(self):
        raise NotImplementedError("Nested config solve is not implemented yet")

    def _nested_config_solve_s2(self):
        raise NotImplementedError("Nested config solve is not implemented yet")

    def _nested_config_solve_s3(self):
        raise NotImplementedError("Nested config solve is not implemented yet")

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


class Z3ConfigSolver:
    def __init__(self, macro_info_file, nested_macros_file=None, results_dir=None):
        """
        Z3 기반 설정 솔버 초기화

        Args:
            macro_info_file: 매크로 정보가 담긴 JSON 파일 경로
            nested_macros_file: 중첩된 매크로 정보가 담긴 JSON 파일 경로 (선택사항)
            results_dir: 결과를 저장할 디렉토리 경로 (선택사항)
        """
        self.macro_info_file = macro_info_file
        self.nested_macros_file = nested_macros_file
        self.macros = {}
        self.nested_macros = {}
        self.macro_vars = {}  # Z3 변수 저장
        self.is_initialized = False
        self.solver = Solver()  # z3.Solver() 대신 Solver()를 사용합니다. (이미 from z3 import Solver 되어 있음)
        self.logger = get_logger(__name__, level=lg.INFO)
        # 결과 저장 디렉토리 설정
        if results_dir:
            self.results_dir = results_dir
        else:
            # 기본 결과 디렉토리: 매크로 정보 파일이 있는 디렉토리 내의 z3_results 폴더
            self.results_dir = os.path.join(os.path.dirname(macro_info_file), "z3_results")

        if not os.path.exists(self.results_dir):
            os.makedirs(self.results_dir, exist_ok=True)

        self._init_macro_variables()

    def _init_macro_variables(self):
        """매크로 정보를 로드하고 Z3 변수로 초기화합니다."""
        # 매크로 정보 로드
        with open(self.macro_info_file, "r", encoding="utf-8") as f:
            self.macros = json.load(f)

        # 중첩된 매크로 정보 로드 (있는 경우)
        if self.nested_macros_file and os.path.exists(self.nested_macros_file):
            with open(self.nested_macros_file, "r", encoding="utf-8") as f:
                self.nested_macros = json.load(f)

        print(f"매크로 개수: {len(self.macros)}")
        print(f"중첩된 매크로 개수: {len(self.nested_macros)}")

        # 각 매크로에 대한 Z3 변수 생성
        for macro_name, info in self.macros.items():
            value_type = info.get("type", "unknown")

            if value_type == "boolean":
                self.macro_vars[macro_name] = Bool(macro_name)  # z3.Bool 대신 Bool 사용
            elif value_type in ["integer", "hex"]:
                self.macro_vars[macro_name] = Int(macro_name)  # z3.Int 대신 Int 사용
            else:
                # 문자열이나 알 수 없는 타입은 정수형으로 처리
                self.macro_vars[macro_name] = Int(macro_name)  # z3.Int 대신 Int 사용

    def _add_value_candidates_constraint(self, macro_name):
        """매크로의 가능한 값들에 대한 제약 조건을 추가합니다."""
        if macro_name not in self.macros or macro_name not in self.macro_vars:
            return

        info = self.macros[macro_name]
        value_type = info.get("type", "unknown")
        candidates = info.get("value_candidates", [])

        if not candidates:
            return

        if value_type == "boolean":
            # Boolean 타입은 True/False만 가능
            pass
        elif value_type in ["integer", "hex"]:
            # 정수형 후보값 제약
            constraints = []
            for candidate in candidates:
                if isinstance(candidate, str) and candidate.startswith("0x"):
                    candidate = int(candidate, 16)
                constraints.append(self.macro_vars[macro_name] == candidate)

            if constraints:
                self.solver.add(Or(constraints))  # z3.Or 대신 Or 사용

    def _add_nested_define_constraints(self):
        """중첩된 #define 매크로에 대한 제약 조건을 추가합니다."""
        print(f"중첩된 매크로 제약 조건 추가 (매크로 개수: {len(self.nested_macros)})")

        for macro_name, info in self.nested_macros.items():
            # 모든 조건부 정의 처리
            all_condition_blocks = info.get("defined_in_conditional_blocks", [])

            for block_info in all_condition_blocks:
                parent_condition = block_info.get("parent_condition")
                value = block_info.get("value")

                if parent_condition and "==" in parent_condition:
                    parts = parent_condition.split("==")
                    left = parts[0].strip()
                    right = parts[1].strip()

                    if left in self.macro_vars:
                        try:
                            if right.startswith("0x"):
                                right_val = int(right, 16)
                            else:
                                right_val = int(right)

                            # 부모 매크로가 특정 값일 때 현재 매크로의 값 설정
                            condition_expr = (
                                self.macro_vars[left] == right_val
                            )  # condition -> condition_expr로 변경 (예약어 충돌 방지)

                            if isinstance(value, bool):
                                if value:
                                    self.solver.add(
                                        Implies(condition_expr, self.macro_vars[macro_name])
                                    )  # z3.Implies 대신 Implies 사용
                                else:
                                    self.solver.add(
                                        Implies(condition_expr, Not(self.macro_vars[macro_name]))
                                    )  # z3.Implies, z3.Not 대신 Implies, Not 사용
                            else:
                                self.solver.add(
                                    Implies(condition_expr, self.macro_vars[macro_name] == value)
                                )  # z3.Implies 대신 Implies 사용
                        except ValueError:
                            pass

    def _add_value_constraints(self):
        """매크로의 기본값에 대한 제약 조건을 추가합니다."""
        for macro_name, info in self.macros.items():
            if "value" in info and macro_name in self.macro_vars:
                value = info["value"]
                value_type = info.get("type", "unknown")

                if value_type == "boolean":
                    if value:
                        self.solver.add(self.macro_vars[macro_name])
                    else:
                        self.solver.add(Not(self.macro_vars[macro_name]))  # z3.Not 대신 Not 사용
                elif value_type in ["integer", "hex"]:
                    self.solver.add(self.macro_vars[macro_name] == value)

    def _parse_condition(self, condition_str, file_path=None):  # condition -> condition_str로 변경
        """조건문을 Z3 표현식으로 변환합니다."""
        if not condition_str:
            return None

        # 간단한 매크로 이름만 있는 경우 (ifdef/ifndef)
        if condition_str in self.macro_vars:
            var = self.macro_vars[condition_str]
            # Int 타입인 경우 0보다 큰지 확인하여 Bool로 변환
            if hasattr(var, 'sort') and str(var.sort()) == 'Int':
                return var > 0
            return var

        # 복잡한 조건 처리
        # == 연산자 처리
        try:
            if "==" in condition_str:
                parts = condition_str.split("==")
                left = parts[0].strip()
                right = parts[1].strip()

            if left in self.macro_vars:
                try:
                    if right.startswith("0x"):
                        right_val = int(right, 16)
                    else:
                        right_val = int(right)
                    return self.macro_vars[left] == right_val
                except ValueError:
                    pass
        
        # > 연산자 처리 (>= 제외)
        if ">" in condition_str and ">=" not in condition_str:
            parts = condition_str.split(">")
            if len(parts) == 2:
                left = parts[0].strip()
                right = parts[1].strip()
                
                if left in self.macro_vars:
                    try:
                        right_val = int(right)
                        return self.macro_vars[left] > right_val
                    except ValueError:
                        pass

        # && 연산자 처리
        if "&&" in condition_str:
            parts = condition_str.split("&&")
            subconditions = []
            for part in parts:
                subexpr = self._parse_condition(part.strip(), file_path)
                if subexpr is not None:
                    # Int 타입이면 Bool로 변환
                    if hasattr(subexpr, 'sort') and str(subexpr.sort()) == 'Int':
                        subexpr = subexpr > 0
                    subconditions.append(subexpr)

                if subconditions:
                    return And(subconditions)  # z3.And 대신 And 사용

        # || 연산자 처리
        if "||" in condition_str:
            parts = condition_str.split("||")
            subconditions = []
            for part in parts:
                subexpr = self._parse_condition(part.strip(), file_path)
                if subexpr is not None:
                    # Int 타입이면 Bool로 변환
                    if hasattr(subexpr, 'sort') and str(subexpr.sort()) == 'Int':
                        subexpr = subexpr > 0
                    subconditions.append(subexpr)

                if subconditions:
                    return Or(subconditions)  # z3.Or 대신 Or 사용
        except Exception as e:
            self.logger.warning(f"조건 파싱 오류: {condition_str} ({e})")
            return None
        return None

    def _add_conditional_block_constraints(self):
        """조건부 블록 구조에 대한 제약 조건을 추가합니다."""
        for macro_name, info in self.macros.items():
            if "conditional_scopes" in info:
                for scope in info["conditional_scopes"]:
                    branch_type = scope.get("branch_type")
                    branch_condition = scope.get("branch_condition")
                    file_path = scope.get("file")

                    if branch_type == "ifdef":
                        if macro_name in self.macro_vars:
                            # #ifdef 매크로 - 매크로가 정의되어 있어야 함
                            # 아무 작업 필요 없음 (매크로 이름이 이미 Z3 변수로 존재)
                            pass
                    elif branch_type == "ifndef":
                        if macro_name in self.macro_vars:
                            # #ifndef 매크로 - 매크로가 정의되지 않아야 함
                            # Z3에서는 이를 Not(매크로)로 표현할 수 있음
                            pass
                    elif branch_type == "if" or branch_type == "elif":
                        # #if나 #elif 조건을 Z3 제약으로 변환
                        z3_expr = self._parse_condition(branch_condition, file_path)
                        if z3_expr is not None:
                            # 이 제약 조건을 직접 추가하지는 않음
                            # 특정 조건 추가 시 필요한 경우 활용
                            pass

    def _save_result(self, query_type, args, solution):
        """솔버 결과를 파일로 저장합니다."""
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")

        # 쿼리 정보 문자열 생성
        if query_type == "s1":
            query_info = f"{args[0]}_{args[1]}"
        elif query_type == "s2":
            query_info = f"{args[0]}_{args[1]}_{args[2]}_{args[3]}"
        elif query_type == "s3":
            query_info = args[0].replace(" ", "_").replace("==", "eq").replace("&&", "and").replace("||", "or")
        else:
            query_info = "unknown"

        # 결과 파일 경로
        result_file = os.path.join(self.results_dir, f"z3_result_{query_type}_{query_info}_{timestamp}.json")

        # 결과 데이터 구성
        result_data = {"query_type": query_type, "query_args": args, "timestamp": timestamp, "solution": solution}

        # 파일로 저장
        with open(result_file, "w", encoding="utf-8") as f:
            json.dump(result_data, f, indent=2, ensure_ascii=False)

        print(f"결과 저장 완료: {result_file}")
        return result_file

    def _nested_config_solve_s1(self, target_macro, target_value):
        """중첩된 설정 구조에서 특정 매크로가 특정 값을 가지기 위한 조건을 찾습니다."""
        print(f"\n[S1 쿼리] {target_macro} = {target_value}일 때의 조건 찾기")

        if target_macro not in self.macro_vars:
            raise ValueError(f"매크로 '{target_macro}'가 정의되지 않았습니다.")

        if not self.is_initialized:
            # 기본 값 제약 조건 추가
            self._add_value_constraints()

            # 조건부 블록 제약 조건 추가
            self._add_conditional_block_constraints()

            # 중첩 매크로 제약 조건 추가
            self._add_nested_define_constraints()
            self.is_initialized = True

        # 대상 매크로 값 제약 추가
        target_info = self.macros.get(target_macro, {})
        value_type = target_info.get("type", "unknown")

        if value_type == "boolean":
            if target_value:
                self.solver.add(self.macro_vars[target_macro])
            else:
                self.solver.add(Not(self.macro_vars[target_macro]))  # z3.Not 대신 Not 사용
        else:
            self.solver.add(self.macro_vars[target_macro] == target_value)

        # Z3 Solver로 해결
        result = self.solver.check()
        if str(result) == "sat":  # z3.sat 대신 "sat" 문자열 비교
            model = self.solver.model()
            solution = {}
            for var_decl in model.decls():  # model -> model.decls() 로 변경, var -> var_decl로 변경
                name = var_decl.name()  # str(var) -> var_decl.name()
                value = model[var_decl]  # model[var] -> model[var_decl]

                # Z3 결과값을 Python 값으로 변환
                if (
                    value.sort() == BoolSort()
                ):  # z3.BoolSort() 대신 BoolSort() 사용 (z3 임포트 방식에 따라 다를 수 있음)
                    solution[name] = is_true(value)  # z3.is_true 대신 is_true 사용
                else:
                    solution[name] = value.as_long()

            print(f"해결 가능: {target_macro} = {target_value}일 때의 해결책 찾음")
            # 결과 파일 저장
            result_file = self._save_result("s1", (target_macro, target_value), solution)
            return solution
        else:
            print(f"해결 불가능: {target_macro} = {target_value}일 때의 해결책 없음")
            return None

    def _nested_config_solve_s2(self, target_macro1, target_value1, target_macro2, target_value2):
        """두 개의 대상 매크로가 동시에 특정 값을 가지기 위한 조건을 찾습니다."""
        print(f"\n[S2 쿼리] {target_macro1} = {target_value1} 및 {target_macro2} = {target_value2}일 때의 조건 찾기")

        if target_macro1 not in self.macro_vars or target_macro2 not in self.macro_vars:
            raise ValueError(f"매크로 '{target_macro1}' 또는 '{target_macro2}'가 정의되지 않았습니다.")

        if not self.is_initialized:
            # 기본 값 제약 조건 추가
            self._add_value_constraints()

            # 조건부 블록 제약 조건 추가
            self._add_conditional_block_constraints()

            # 중첩 매크로 제약 조건 추가
            self._add_nested_define_constraints()
            self.is_initialized = True

        # 첫 번째 대상 매크로 값 제약 추가
        target1_info = self.macros.get(target_macro1, {})
        value_type1 = target1_info.get("type", "unknown")

        if value_type1 == "boolean":
            if target_value1:
                self.solver.add(self.macro_vars[target_macro1])
            else:
                self.solver.add(Not(self.macro_vars[target_macro1]))  # z3.Not 대신 Not 사용
        else:
            self.solver.add(self.macro_vars[target_macro1] == target_value1)

        # 두 번째 대상 매크로 값 제약 추가
        target2_info = self.macros.get(target_macro2, {})
        value_type2 = target2_info.get("type", "unknown")

        if value_type2 == "boolean":
            if target_value2:
                self.solver.add(self.macro_vars[target_macro2])
            else:
                self.solver.add(Not(self.macro_vars[target_macro2]))  # z3.Not 대신 Not 사용
        else:
            self.solver.add(self.macro_vars[target_macro2] == target_value2)

        # Z3 Solver로 해결
        result = self.solver.check()
        if str(result) == "sat":  # z3.sat 대신 "sat" 문자열 비교
            model = self.solver.model()
            solution = {}
            for var_decl in model.decls():  # model -> model.decls() 로 변경, var -> var_decl로 변경
                name = var_decl.name()  # str(var) -> var_decl.name()
                value = model[var_decl]  # model[var] -> model[var_decl]

                # Z3 결과값을 Python 값으로 변환
                if value.sort() == BoolSort():  # z3.BoolSort() 대신 BoolSort() 사용
                    solution[name] = is_true(value)  # z3.is_true 대신 is_true 사용
                else:
                    solution[name] = value.as_long()

            print(
                f"해결 가능: {target_macro1} = {target_value1} 및 {target_macro2} = {target_value2}일 때의 해결책 찾음"
            )
            # 결과 파일 저장
            result_file = self._save_result(
                "s2", (target_macro1, target_value1, target_macro2, target_value2), solution
            )
            return solution
        else:
            print(
                f"해결 불가능: {target_macro1} = {target_value1} 및 {target_macro2} = {target_value2}일 때의 해결책 없음"
            )
            return None

    def _nested_config_solve_s3(self, target_condition):
        """주어진 조건이 충족되기 위한 매크로 설정을 찾습니다."""
        print(f"\n[S3 쿼리] 조건 '{target_condition}'이 충족되기 위한 설정 찾기")

        if not self.is_initialized:
            # 기본 값 제약 조건 추가
            self._add_value_constraints()

            # 조건부 블록 제약 조건 추가
            self._add_conditional_block_constraints()

            # 중첩 매크로 제약 조건 추가
            self._add_nested_define_constraints()

            self.is_initialized = True

        # 대상 조건 제약 추가
        z3_expr = self._parse_condition(target_condition)
        if z3_expr is not None:
            self.solver.add(z3_expr)
        else:
            error_msg = f"조건 '{target_condition}'을 Z3 표현식으로 변환할 수 없습니다."
            print(f"오류: {error_msg}")
            raise ValueError(error_msg)

        # Z3 Solver로 해결
        result = self.solver.check()
        if str(result) == "sat":  # z3.sat 대신 "sat" 문자열 비교
            model = self.solver.model()
            solution = {}
            for var_decl in model.decls():  # model -> model.decls() 로 변경, var -> var_decl로 변경
                name = var_decl.name()  # str(var) -> var_decl.name()
                value = model[var_decl]  # model[var] -> model[var_decl]

                # Z3 결과값을 Python 값으로 변환
                if value.sort() == BoolSort():  # z3.BoolSort() 대신 BoolSort() 사용
                    solution[name] = is_true(value)  # z3.is_true 대신 is_true 사용
                else:
                    solution[name] = value.as_long()

            print(f"해결 가능: 조건 '{target_condition}'이 충족되는 해결책 찾음")
            # 결과 파일 저장
            result_file = self._save_result("s3", (target_condition,), solution)
            return solution
        else:
            print(f"해결 불가능: 조건 '{target_condition}'이 충족되는 해결책 없음")
            return None

    def _nested_config_solve_s4(self, target_conditions):
        """여러 조건들이 모두 충족되기 위한 매크로 설정을 찾습니다."""
        print(f"\n[S4 쿼리] {len(target_conditions)}개의 조건이 모두 충족되기 위한 설정 찾기")

        if not self.is_initialized:
            # 기본 값 제약 조건 추가
            self._add_value_constraints()

            # 조건부 블록 제약 조건 추가
            self._add_conditional_block_constraints()

            # 중첩 매크로 제약 조건 추가
            self._add_nested_define_constraints()
            self.is_initialized = True

        # 모든 조건에 대한 제약 추가
        for condition in target_conditions:
            # #if, #ifdef, #ifndef 등의 전처리기 지시문 제거
            condition = condition.strip()
            if condition.startswith("#if "):
                condition = condition[4:].strip()
            elif condition.startswith("#ifdef "):
                condition = condition[7:].strip()
            elif condition.startswith("#ifndef "):
                condition = condition[8:].strip()

            self.logger.debug(f"[-] 조건 '{condition}'을 Z3 표현식으로 변환합니다.")
            
            z3_expr = None
            try:
                z3_expr = self._parse_condition(condition)
            except Exception as e:
                self.logger.warning(
                    f"[-] 조건 '{condition}'을 Z3 표현식으로 변환할 수 없습니다. 이 조건은 무시됩니다."
                )
                continue
            
            # None 체크 추가
            if z3_expr is None:
                self.logger.warning(
                    f"[-] 조건 '{condition}'이 None을 반환했습니다. 이 조건은 무시됩니다."
                )
                continue

            if z3_expr:
                self.solver.add(z3_expr)

        # Z3 Solver로 해결
        result = self.solver.check()
        if str(result) == "sat":
            model = self.solver.model()
            solution = {}
            for var_decl in model.decls():
                name = var_decl.name()
                value = model[var_decl]

                # Z3 결과값을 Python 값으로 변환
                if value.sort() == BoolSort():
                    solution[name] = is_true(value)
                else:
                    solution[name] = value.as_long()

            print(f"해결 가능: {len(target_conditions)}개의 조건이 모두 충족되는 해결책 찾음")
            # 결과 파일 저장
            result_file = self._save_result("s4", (str(target_conditions),), solution)
            return solution
        else:
            print(f"해결 불가능: {len(target_conditions)}개의 조건이 모두 충족되는 해결책 없음")
            return None

    def solve(self, query_type, *args):
        """설정 쿼리를 해결합니다."""
        if query_type == "s1":
            if len(args) != 2:
                raise ValueError("S1 쿼리는 2개의 인자(target_macro, target_value)가 필요합니다.")
            return self._nested_config_solve_s1(args[0], args[1])
        elif query_type == "s2":
            if len(args) != 4:
                raise ValueError(
                    "S2 쿼리는 4개의 인자(target_macro1, target_value1, target_macro2, target_value2)가 필요합니다."
                )
            return self._nested_config_solve_s2(args[0], args[1], args[2], args[3])
        elif query_type == "s3":
            if len(args) != 1:
                raise ValueError("S3 쿼리는 1개의 인자(target_condition)가 필요합니다.")
            return self._nested_config_solve_s3(args[0])
        elif query_type == "s4":
            if len(args) != 1 or not isinstance(args[0], list):
                raise ValueError("S4 쿼리는 1개의 인자(target_conditions list)가 필요합니다.")
            return self._nested_config_solve_s4(args[0])
        else:
            raise ValueError(f"알 수 없는 쿼리 타입: {query_type}")


# 사용 예시
# if __name__ == "__main__":
#     # 매크로 정보 파일과 중첩 매크로 정보 파일 경로
#     current_dir = os.path.abspath(os.path.dirname(__file__))
#     macro_dir = os.path.join(os.path.dirname(current_dir), "analysis_results", "macro_based")

#     macro_info_file = os.path.join(macro_dir, "macro_info.json")
#     nested_macros_file = os.path.join(macro_dir, "nested_macros.json")

#     # 결과 저장 디렉토리
#     results_dir = os.path.join(os.path.dirname(current_dir), "z3_results")

#     # Z3ConfigSolver 초기화
#     solver = Z3ConfigSolver(macro_info_file, nested_macros_file, results_dir)

#     print("\n=== Z3 솔버 테스트 ===")
#     print(f"매크로 정보 파일: {macro_info_file}")
#     print(f"중첩 매크로 파일: {nested_macros_file}")
#     print(f"결과 저장 디렉토리: {results_dir}")

#     # S1 쿼리 예시: 특정 매크로가 특정 값을 가지도록 하는 설정 찾기
#     result_s1 = solver.solve('s1', 'TEST_NESTED_DEFINE', 1)
#     print(f"S1 결과 요약: {result_s1 is not None}")

#     # S2 쿼리 예시: 두 매크로가 동시에 특정 값을 가지도록 하는 설정 찾기
#     result_s2 = solver.solve('s2', 'TEST_NESTED_DEFINE', 1, 'SIBLING_CONFIG', 1)
#     print(f"S2 결과 요약: {result_s2 is not None}")

#     # S3 쿼리 예시: 특정 조건이 충족되도록 하는 설정 찾기
#     result_s3 = solver.solve('s3', 'TEST_NESTED_DEFINE == 1 && SIBLING_CONFIG == 1')
#     print(f"S3 결과 요약: {result_s3 is not None}")

#     print("\n모든 테스트 완료!")
