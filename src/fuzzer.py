import copy
from src.config.config import ConfigFactory
from src.adapter.adapter import BaseAdapter
from src.utils.exception import TargetFunctionNotFoundException

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
        self.steps = []
        self.steps_count = 0
        self.output_base_dir = "output"
        self.adapter = adapter
        self.verbose = verbose

    def fuzz(self):
        function_results = []
        output_dir = f"{self.output_base_dir}/{self.adapter.name}_{self.steps_count}"

        # 1. create config file
        config_file = self.current_config.create_config_header(f"{output_dir}/config.h")

        # 2. set config file, result dir to adapter
        self.adapter.set_analyze_result_dir(output_dir)
        self.adapter.set_config_file_src(config_file)

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

    # TODO: mutate 휴리스틱 룰 정리해놓기
    # Stage 1. 코드 파싱 단계
    # Stage 2. Feedback을 통한 mutation 단계
    # 스택(파일)과 관련있는 macro들만 퍼징할수있게끔 구현
    def mutate(self, target_function: str):
        if target_function not in self.adapter.get_thread_functions():
            raise TargetFunctionNotFoundException(f"Target function {target_function} not found")

        mutation_config = None

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

        self.current_config.flip_config(self.current_config.random_select_config().get("name"))
        self.current_config.flip_config(self.current_config.random_select_config().get("name"))
