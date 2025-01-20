import copy
import os.path
import os
import random

# from mutator.mutate import related_based_mutate
from src.ir2dot.irlib.file import File
from src.config.config import Config, ConfigFactory
from src.adapter.adapter import BaseAdapter
from src.utils.exception import TargetFunctionNotFoundException
from src.ir2dot.gccir2dot import Function
from src.applyer.applyer import Applyer

# from logging import logger


class Fuzzer:
    def __init__(
        self,
        base: str,
        seed_macro_file: str,
        adapter: BaseAdapter,
        verbose: bool = False,
    ):
        self.base = base
        self.seed: ConfigFactory = ConfigFactory(seed_macro_file)
        self.current_config: ConfigFactory = ConfigFactory(seed_macro_file)
        self.steps: list[dict] = []
        self.applyer: Applyer = Applyer(self.base)
        self.steps_count = 0
        self.output_base_dir = "output"
        self.adapter = adapter
        self.verbose = verbose

        # 특정 스레드 함수의 callgraph에 해당하는 파일들
        # self.initial_analyze 를 먼저해야함
        # dict["function_name": set[File]]
        self.related_files_per_function: dict[str, set[File]] = {}

        # 특정 스레드 함수가 사용하는 macro 리스트
        # self.initial_analyze 를 먼저해야함
        # dict["function_name": set[str]]
        self.related_macros_per_function: dict[str, set[str]] = {}

        # fuzzer stting
        # 퍼징 시 매크로를 찾을때, 해당 line 이상 영향력을 끼치는 매크로들만 수정합니다.
        self.fuzzer_line_threshold = 30

    def initial_analyze(self, target_function: str):
        self.adapter.initial_analyze(target_function)
        # 방문한 함수들에 해당하는 파일들 모두 추가
        visited_functions: list[Function] = self.adapter.initial_analyze_result["visited"]
        if not self.related_files_per_function.get(target_function):
            self.related_files_per_function[target_function] = set()
        if not self.related_macros_per_function.get(target_function):
            self.related_macros_per_function[target_function] = set()

        # 특정 함수가 방문하는 파일들 리스트로 추가
        for function in visited_functions:
            self.related_files_per_function[target_function].add(function.parent_file)

        # 특정 스레드 함수가 사용하는 macro 리스트
        for file in list(self.related_files_per_function[target_function]):
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
                            self.related_macros_per_function[target_function].add(macro_name)
                            break

        print(self.related_macros_per_function)
        # exit()

    def fuzz(self):
        function_results = []
        related_files = []
        output_dir = f"{self.output_base_dir}/{self.adapter.name}_{self.steps_count}"

        # 1. create config file
        target_configs = []
        for key in self.related_macros_per_function.keys():
            for macro in self.related_macros_per_function[key]:
                target_configs.append(macro)

        if self.applyer:
            self.applyer.apply(self.current_config, target_configs)

        # config_file = self.current_config.create_config_header(
        #     f"{output_dir}/config.h",
        #     target_configs,
        # )

        # 2. set config file, result dir to adapter
        self.adapter.set_analyze_result_dir(output_dir)
        # self.adapter.set_config_file_src(config_file)

        dump_result_filename = f"result_{self.adapter.name}_{self.steps_count}.json"
        # build result
        build_result = self.adapter.build(self.current_config)

        # build_result = True
        if build_result:
            function_results = self.adapter.analyze()
            self.adapter.dump_result(f"{self.output_base_dir}/{dump_result_filename}", "json")

            # dump steps
            self.steps.append(
                {
                    "build_result": build_result,
                    "function_results": function_results,
                    "step": self.steps_count,
                    "config": copy.deepcopy(self.current_config),
                }
            )
        self.steps_count += 1

        if self.verbose:
            print(f"[+] Step {self.steps_count} done. Build Result: ({build_result})")

        if self.applyer:
            self.applyer.revert()

    # TODO: mutate 휴리스틱 룰 정리해놓기
    # Stage 1. 코드 파싱 단계
    # Stage 2. Feedback을 통한 mutation 단계
    # 스택(파일)과 관련있는 macro들만 퍼징할수있게끔 구현
    def mutate(self, target_function: str, methods: list[str] = ["related", "stack", "use-codesize"]):
        threshold = 2
        for method in methods:
            if method not in ["related", "stack", "use-codesize"]:
                raise ValueError(f"Invalid method: {method}")

        if target_function not in self.adapter.get_thread_functions():
            raise TargetFunctionNotFoundException(f"Target function {target_function} not found")

        target_macros: list[Config] = []
        if "related" in methods:
            target_macros = list(self.related_macros_per_function[target_function])
        else:
            if isinstance(self.current_config.config, dict):
                target_macros = list(self.current_config.config.keys())
            elif isinstance(self.current_config.config, list):
                target_macros = [item.name for item in self.current_config.config]

        mutation_config = None

        """
            2회 이상 빌드했을때, 스택 사이즈가 더 큰 것을 찾아 해당 Configuration을 가져와 퍼징
        """
        if len(self.steps) >= 2:
            # 이전 결과
            current_function_results = self.steps[-1]["function_results"]
            before_function_results = self.steps[-2]["function_results"]

            current_target_function_result = [
                result for result in current_function_results if result["name"] == target_function
            ][0]
            before_target_function_result = [
                result for result in before_function_results if result["name"] == target_function
            ][0]

            if current_target_function_result["biggest_stack"] >= before_target_function_result["biggest_stack"]:
                mutation_config = self.steps[-1]["config"]
            else:
                mutation_config = self.steps[-2]["config"]

        if mutation_config:
            self.current_config = mutation_config

        for i in range(threshold):
            random_macro = random.choice(target_macros)
            self.current_config.change_config(random_macro)

        # TODO: 영향 받는것만 추가로 퍼징
