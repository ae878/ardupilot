import copy
import os.path
import os
import random
import time
import json
import math
import random
from typing import Union

# from mutator.mutate import related_based_mutate
from src.ir2dot.irlib.file import File
from src.config.config import Config, ConfigFactory
from src.adapter.adapter import BaseAdapter
from src.utils.exception import TargetFunctionNotFoundException
from src.ir2dot.gccir2dot import Function
from src.ir2dot.irlib.exceptions import FunctionNotFoundException
from src.ir2dot.irlib.encoder import FunctionEncoder
from src.applier.applier import Applier
from src.config.z3_config_solver import Z3ConfigSolver, Z3ConfigValidator
from src.utils.logging import get_logger
from src.utils.logging import lg


# from logging import self.logge
class FuzzerStep:
    def __init__(
        self,
        build_result: bool,
        function_results: list,
        step: int,
        config: ConfigFactory,
        start_time: float,
        apply_time: float,
        build_time: float,
        analyze_time: float,
        end_time: float,
        unique_stack_smash_count: int,
    ):
        self.build_result = build_result
        self.function_results = function_results
        self.step = step
        self.config = copy.deepcopy(config)
        self.start_time = start_time
        self.apply_time = apply_time
        self.build_time = build_time
        self.analyze_time = analyze_time
        self.end_time = end_time
        self.unique_stack_smash_count = unique_stack_smash_count

    def dump_result_to_file(self, output_base_filename: str):
        function_file_name = f"{output_base_filename}_function_results.json"
        config_file_name = f"{output_base_filename}_config_results.json"
        meta_file_name = f"{output_base_filename}_meta_results.json"
        # create directory if not exists
        os.makedirs(os.path.dirname(output_base_filename), exist_ok=True)

        with open(function_file_name, "w") as f:
            json.dump(self.function_results, f, indent=2, cls=FunctionEncoder)

        with open(config_file_name, "w") as f:
            json.dump(self.config.dump_config(), f, indent=2)

        with open(meta_file_name, "w") as f:
            json.dump(
                {
                    "build_result": self.build_result,
                    "start_time": self.start_time,
                    "apply_time": self.apply_time,
                    "build_time": self.build_time,
                    "analyze_time": self.analyze_time,
                    "end_time": self.end_time,
                    "total_time": self.end_time - self.start_time,
                    "unique_stack_smash_count": self.unique_stack_smash_count,
                },
                f,
            )


class Fuzzer:
    def __init__(
        self,
        base: str,
        adapter: BaseAdapter,
        seed_macro_file: Union[str, None] = None,
        config: Union[ConfigFactory, None] = None,
        verbose: bool = False,
        threshold: int = 2,
        sat_acquire_min_codesize: int = 10,
    ):
        if not seed_macro_file:
            raise ValueError("seed_macro_file must be provided")

        if not config:
            raise ValueError("config must be provided")

        self.base = base
        self.seed: ConfigFactory = ConfigFactory(seed_macro_file) if seed_macro_file else config
        self.current_config: ConfigFactory = self.seed
        # For the memory issue, we use recent_steps instead of steps
        # self.steps: list[FuzzerStep] = []
        self.max_recent_steps = 10  # Maximum number of recent steps to store
        self.recent_steps: list[FuzzerStep] = []  # Store up to max_recent_steps steps
        self.recent_step: FuzzerStep = None  # For backward compatibility
        self.applyer: Applier = Applier(self.base)
        self.steps_count = 0
        self.output_base_dir = "output"
        self.adapter = adapter
        self.verbose = verbose
        self.threshold = threshold
        self.sat_acquire_min_codesize = sat_acquire_min_codesize
        # 특정 스레드 함수의 callgraph에 해당하는 파일들
        # self.initial_analyze 를 먼저해야함
        # dict["function_name": set[File]]
        self.related_files_per_function: dict[str, set[File]] = {}

        # 특정 스레드 함수가 사용하는 macro 리스트
        # self.initial_analyze 를 먼저해야함
        # dict["function_name": set[str]]
        self.related_macros_per_function: dict[str, set[Config]] = {}

        # fuzzer stting
        # 퍼징 시 매크로를 찾을때, 해당 line 이상 영향력을 끼치는 매크로들만 수정합니다.
        self.fuzzer_line_threshold = 30

        # Unique stack smash that found
        self.unique_stack_smash_count = 0
        self.unique_stack_smashes = set()

        self.z3_config_solver = Z3ConfigSolver(seed_macro_file)

        self.logger = get_logger(__name__, level=lg.DEBUG)

    def initial_analyze(
        self,
        target_functions: list[str],
        initial_analyze_result_dir: str = "initial_analyze",
    ):
        """
        이 함수는 특정 함수에 대해 초기 분석을 진행합니다
        소스코드를 이용해 만든 macros.json 파일을 이용해 분석을 진행합니다

        이를 이용해, 특정 함수와 관련있는 파일들과, 매크로들을 찾아 저장합니다
        """
        self.logger.info(f"[+] Initial analyze of the fuzzer {self.base}")
        self.adapter.initial_analyze(initial_analyze_result_dir)
        for target_function in target_functions:
            initial_analyze_result = {}
            try:
                initial_analyze_result = self.adapter.initial_adapter_get_analyze_result(target_function)
            except FunctionNotFoundException as e:
                self.logger.warning(f"[-] Function {target_function} not found")
                continue
            except Exception as e:
                self.logger.error(f"[-] Error occurred while initial analyzing {target_function}: {e}")
                continue
            # 방문한 함수들에 해당하는 파일들 모두 추가
            visited_functions: list[Function] = initial_analyze_result.get("visited", [])
            if not self.related_files_per_function.get(target_function):
                self.related_files_per_function[target_function] = set()
            if not self.related_macros_per_function.get(target_function):
                self.related_macros_per_function[target_function] = set()

            # 특정 함수가 방문하는 파일들 리스트로 추가
            for function in visited_functions:
                self.related_files_per_function[target_function].add(function.parent_file)

            # 특정 스레드 함수가 사용하는 macro 리스트
            for file in list(self.related_files_per_function[target_function]):
                if file:
                    analyzer_file_name = os.path.basename(file.name)
                    analyzer_file_name = ".".join(analyzer_file_name.split(".")[:2])

                    if isinstance(self.seed.config, list):
                        raise NotImplementedError("list type config is not supported")

                    elif isinstance(self.seed.config, dict):
                        for macro_name, macro_info in self.seed.config.items():
                            # 특정 macro가 해당 macro를 실제로 쓰는경우
                            for filename in macro_info.used_in:
                                filename = os.path.basename(filename)
                                if analyzer_file_name in filename:
                                    self.related_macros_per_function[target_function].add(macro_info)
                                    break
                else:
                    self.logger.warning(f"[-] File for target function {target_function} not found")

        # exit()

    def fuzz(self, methods: list[str] = ["related"], is_dry_run: bool = False):

        function_results = []
        related_files = []
        output_dir = os.path.join(self.output_base_dir, f"{self.adapter.name}_{self.steps_count}")

        start_time = time.time()
        # 1. Apply configs
        target_configs = []
        if "related" in methods:
            for key in self.related_macros_per_function.keys():
                for macro in self.related_macros_per_function[key]:
                    target_configs.append(macro)
            # Randomly add two configs
            random_candidates = list(self.current_config.config.values())
            random.shuffle(random_candidates)
            added = 0
            # Add two random configs if it is not in target_configs
            for candidate in random_candidates:
                if candidate not in target_configs:
                    target_configs.append(candidate)
                    added += 1
                if added == 2:
                    break
        else:
            target_configs = list(self.current_config.config.values())
        try:
            if self.applyer:
                self.applyer.apply(self.current_config, target_configs)
            apply_time = time.time()
            # print(target_configs)

            # config_file = self.current_config.create_config_header(
            #     f"{output_dir}/config.h",
            #     target_configs,
            # )

            # 2. set config file, result dir to adapter
            self.adapter.set_analyze_result_dir(output_dir)

            dump_result_filename = f"result_{self.adapter.name}_{self.steps_count}.json"

            # 3. Build
            try:
                build_result = self.adapter.build(self.current_config)
            except Exception as e:
                self.logger.error(f"[-] Error occurred while building: {e}")
                build_result = False
            build_time = time.time()
            function_results = []
            # 4. Analyze
            if is_dry_run:
                self.logger.info("[+] Dry run mode, skipping analysis")
                build_result = True
                return
            if build_result:
                function_results = self.adapter.analyze()
                analyze_time = time.time()
            else:
                analyze_time = time.time()

            for function_result in function_results:
                biggest_stack = int(function_result["biggest_stack"])
                source_size = int(function_result["source_size"])
                biggest_path = str(json.dumps(function_result["biggest_path"], cls=FunctionEncoder))
                if biggest_stack > 0:
                    if biggest_stack > source_size and biggest_path not in self.unique_stack_smashes:
                        self.unique_stack_smash_count += 1
                        self.unique_stack_smashes.add(biggest_path)

            self.recent_step = FuzzerStep(
                build_result=build_result,
                function_results=function_results,
                step=self.steps_count,
                config=copy.deepcopy(self.current_config),
                start_time=start_time,
                apply_time=apply_time,
                build_time=build_time,
                analyze_time=analyze_time,
                end_time=time.time(),
                unique_stack_smash_count=self.unique_stack_smash_count,
            )

            # Add to recent_steps and maintain only last max_recent_steps steps
            self.recent_steps.append(self.recent_step)
            if len(self.recent_steps) > self.max_recent_steps:
                self.recent_steps.pop(0)

            self.recent_step.dump_result_to_file(f"{self.output_base_dir}/{dump_result_filename}")
            self.logger.info(
                f"[+] Step {self.steps_count} done. Build Result: ({build_result})\tSave into: {self.output_base_dir}/{dump_result_filename}"
            )
            self.steps_count += 1

            if self.verbose:
                print(f"[+] Step {self.steps_count} done. Build Result: ({build_result})")

            # 5. Revert
        except Exception as e:
            self.logger.error(f"[-] Error occurred during fuzzing: {e}")
        finally:
            if self.applyer:
                if is_dry_run:
                    is_really_revert = input("Dry run ended. Do you want to revert applier? (N/y)")
                    if is_really_revert.lower() == "y":
                        self.applyer.revert()
                else:
                    self.applyer.revert()

    def change_config_with_seed(self, config: ConfigFactory):
        self.current_config = config
        self.seed = config

    # Stage 1. 코드 파싱 단계
    # Stage 2. Feedback을 통한 mutation 단계
    # 스택(파일)과 관련있는 macro들만 퍼징할수있게끔 구현
    def mutate(
        self, target_functions: list[str], methods: list[str] = ["related"], sat_acquire_min_codesize: int = -1
    ):
        """
        Support methods:
        - related: fuzz related macros with the target function
        - stack: Use greedy-methods for searching stacks, and mutate the biggest stack
        - use-codesize: Target macros that actually change the code size
        - sat-validate: Validate the configuration with SAT solver
        - sat-solve: Solve the configuration with SAT solver


        Support methods:
        - related: fuzz related macros with the target function
        - stack: Use greedy-methods for searching stacks, and mutate the biggest stack
        - use-codesize: Target macros that actually change the code size
        - sat-validate: Validate the configuration with SAT solver
        - sat-solve: 특정 codesize 이상인 Branch 중 하나를 랜덤하게 선택함함

        """
        max_validate_retry = 10
        if sat_acquire_min_codesize == -1:
            sat_acquire_min_codesize = self.sat_acquire_min_codesize

        # Check method/target_functions are valid
        for method in methods:
            if method not in ["related", "stack", "use-codesize", "sat-validate", "sat-solve"]:
                raise ValueError(f"Invalid method: {method}")

        # Check if the most recent build failed and revert to previous config if needed
        if len(self.recent_steps) >= 1 and not self.recent_steps[-1].build_result:
            if len(self.recent_steps) >= 2:
                self.current_config = copy.deepcopy(self.recent_steps[-2].config)
                self.logger.info("[+] Reverting to previous configuration due to build failure")
            else:
                self.logger.warning("[-] No previous configuration to revert to")

        for _ in range(max_validate_retry):
            for target_function in target_functions:
                if target_function not in self.adapter.get_thread_functions():
                    self.logger.warning(f"Target function {target_function} not found")

            target_macros: list[Config] = []

            # Check [related] method
            # if related method is used, fuzz related macros with the target function
            # else, fuzz all macros
            if "related" in methods:
                for target_function in target_functions:
                    target_macro_list = list(self.related_macros_per_function.get(target_function, set()))
                    if not target_macro_list:
                        self.logger.warning(
                            f"No related macros found for {target_function}, so I'll not include them."
                        )
                    else:
                        target_macros.extend(target_macro_list)

            if len(target_macros) == 0:
                if isinstance(self.current_config.config, list):
                    raise NotImplementedError("list type config is not supported")
                for key, macro in self.current_config.config.items():
                    target_macros.append(macro)

            # Check [use-codesize] method
            if "use-codesize" in methods:
                new_target_macros = []
                for target_macro in target_macros:
                    scope_size = 0
                    for scope in target_macro.conditional_scopes:
                        scope_size += scope["scope_size"]
                    if scope_size > self.fuzzer_line_threshold:
                        new_target_macros.append(target_macro)
                if len(new_target_macros) == 0:
                    raise ValueError("No macros to fuzz")
                target_macros = new_target_macros

            mutation_config = None
            self.logger.debug(f"[+] target_macros: {target_macros}")

            """
                2회 이상 빌드했을때, 스택 사이즈가 더 큰 것을 찾아 해당 Configuration을 가져와 퍼징
            """
            if "stack" in methods:
                if len(self.recent_steps) >= 2:
                    # 이전 결과
                    current_function_results = self.recent_steps[-1].function_results
                    before_function_results = self.recent_steps[-2].function_results

                    current_target_function_result = [
                        result for result in current_function_results if result["name"] == target_function
                    ][0]
                    before_target_function_result = [
                        result for result in before_function_results if result["name"] == target_function
                    ][0]

                    if (
                        current_target_function_result["biggest_stack"]
                        >= before_target_function_result["biggest_stack"]
                    ):
                        mutation_config = self.recent_steps[-1].config
                    else:
                        mutation_config = self.recent_steps[-2].config

                if mutation_config:
                    self.current_config = mutation_config

            if "sat-solve" in methods:
                smt_equations = []
                # 타겟하는 함수와 연관있는 파일만 sat-solve 경로 내에 포함
                target_files: set[File] = set()
                for target_function in target_functions:
                    temp_files = self.related_files_per_function.get(target_function, set())
                    if temp_files:
                        target_files.update(temp_files)
                print("====================")
                print(f"[+] Target files: {target_files}")
                print("=====================")
                for target_macro in target_macros:
                    # TODO: Apply only related files
                    smt_equations.extend(target_macro.select_block(sat_acquire_min_codesize, target_files))
                if len(smt_equations) == 0:
                    self.logger.warning("[-] No macros to fuzz")
                    # continue
                with open("./total_smt_equations.json", "w") as f:
                    json.dump(smt_equations, f, indent=2)

                current_equations = smt_equations.copy()
                solution = self.z3_config_solver.solve("s4", current_equations)
                while not solution and len(current_equations) > 1:
                    remove_count = max(1, math.ceil(len(current_equations) * 0.1))
                    remove_indices = random.sample(range(len(current_equations)), remove_count)
                    current_equations = [eq for i, eq in enumerate(current_equations) if i not in remove_indices]
                    self.logger.info(f"No solution found, retrying with {len(current_equations)} equations...")
                    solution = self.z3_config_solver.solve("s4", current_equations)
                if not solution:
                    self.logger.warning(
                        "[-] No solution found, it means the equations are unsatisfiable... Something wrong with Z3 Solver?"
                    )
                else:
                    self.logger.info(f"[+] Solution found: Total {len(solution.keys())} macros")
                    for solution_key in solution.keys():
                        self.logger.debug(f"    {solution_key}: {solution[solution_key]}")
                        self.current_config.change_config(solution_key, solution[solution_key])
            """
                랜덤하게 2개 mutate
            """
            for i in range(self.threshold):
                # print(target_macros)
                random_macro = random.choice(target_macros)
                self.current_config.change_config(random_macro.name)

            if "sat-validate" in methods:
                is_satisfied, unsatisfied_macros = self.current_config.validate_configuration()
                if not is_satisfied:
                    self.logger.warning("[-] SAT validate failed, Trying to fix some unsatisfied macros..")
                    # Randomly select some macros to fix
                    num_to_fix = max(
                        1, len(unsatisfied_macros) // 2
                    )  # Fix at least 1, at most half of unsatisfied macros
                    macros_to_fix = random.sample(unsatisfied_macros, num_to_fix)

                    # Fix selected macros
                    for macro_name, current_value, expected_value in macros_to_fix:
                        self.logger.info(f"[-] Fixing {macro_name}: {current_value} -> {expected_value}")
                        self.current_config.change_config(macro_name, expected_value)
                    continue
                else:
                    break
            else:
                break

        return
