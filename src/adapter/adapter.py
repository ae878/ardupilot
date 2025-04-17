from abc import ABC, abstractmethod
from typing import Literal, Union
import csv
import json
import os
from src.config.config import ConfigFactory
from src.ir2dot.gccir2dot import Parser
from src.utils.logging import get_logger

logger = get_logger(__name__)


class BaseAdapter(ABC):
    @abstractmethod
    def __init__(
        self,
        base: str,
        build_commands: list[str],
        thread_functions_file_path: str,
        analyze_result_dir: str,
        verbose: bool = False,
        build_base: str = "",
    ):
        self.base = base
        self.build_commands = build_commands
        """
        example
        [
            {
                "thread": "AP_OAPathPlanner::avoidance_thread",
                "size": "8192"
            }
        ]
        """
        self.thread_functions: list[dict[str, str]] = []
        self.thread_functions_file_path = thread_functions_file_path
        self.analyze_result_dir = analyze_result_dir
        self.verbose = verbose
        self.name = ""
        self.build_base = build_base
        # For the analyzer
        self.function_results: list[dict] = []
        self.visited_functions: dict[str, set] = {}
        self.initial_analyze_result: dict[str, Union[set, int, list, dict]] = {}
        self.parser: Union[Parser, None] = None

    def get_thread_functions(self):
        thread_functions = []
        for function in self.thread_functions:
            thread_functions.append(function["thread"])
        return thread_functions

    def set_analyze_result_dir(self, analyze_result_dir: str):
        self.analyze_result_dir = analyze_result_dir

    def set_config_file_src(self, config_file_src: str):
        self.config_file_src = config_file_src

    @abstractmethod
    def build(self, config: Union[ConfigFactory, str, None] = None) -> bool:
        """
        Batch build the script
        You can just using your own build command (such as make, cmake, etc..)
        Or just calling batch gcc commands directly

        The point is, you MUST create *.su, *.optimized, *.class files in the base directory

        return True if build success else False
        """
        pass

    def initial_analyze(self, output_dir: str = "initial_analyze"):
        """
        In this method, fuzzer will initially analyze the project
        this makes a callgraph of the project, and it gives hint to the fuzzer

        For detail: after getting the callgraph, fuzzer find the macro that uses only in the function
        and only mutate the macros
        """
        if self.verbose:
            logger.debug(f"[+] ================ Initial Analyze Start ================")

        try:
            os.makedirs(output_dir, exist_ok=True)
        except OSError:
            pass

        # parse the project
        parser = None
        if os.path.exists(f"{output_dir}/phase2.pkl"):
            logger.debug(f"[+] Found Pickle File: {output_dir}/phase2.pkl")
            self.parser = Parser(self.base, "", output_dir, is_save_pkl=True, is_load_pkl=False, is_only_test=False)
            self.parser.load_from_pkl(f"phase2.pkl")
            logger.debug(f"[+] ================ Load from Pickle ================")
        else:
            self.parser = Parser(self.base, "", output_dir, is_save_pkl=True, is_load_pkl=False, is_only_test=False)
            self.parser.parse()
        # print(parser.functions)
        # try:
        #     function = parser.find_function(target_function)
        #     result = parser.bfs(function)
        #     self.initial_analyze_result = result
        # except Exception as e:
        #     logger.error(f"[-] Initial Analyze Failed: {e}")
        #     raise e

        if self.verbose:
            logger.debug(f"[+] ================ Initial Analyze End ================")

        return

    def initial_adapter_get_analyze_result(self, target_function) -> dict:
        if self.parser is None:
            raise Exception("Parser is not initialized")
        try:
            function = self.parser.find_function(target_function)
            result = self.parser.bfs(function)
            return result
        except Exception as e:
            logger.error(f"[-] Initial Analyze Failed: {e}")
            raise e

    # @abstractmethod
    def analyze(self):
        """
        Analyze the project by given build result

        """
        logger.debug(f"[+] ================ Analyze Start ================")
        try:
            os.makedirs(self.analyze_result_dir, exist_ok=True)
        except OSError:
            pass

        # remote all files in the analyze result directory
        for file in os.listdir(self.analyze_result_dir):
            os.remove(os.path.join(self.analyze_result_dir, file))

        parser_base = self.build_base if self.build_base else self.base
        parser = Parser(
            parser_base, "", self.analyze_result_dir, is_save_pkl=True, is_load_pkl=False, is_only_test=False
        )

        parser.parse()

        # analyze it
        function_results = []
        for function_info in self.thread_functions:
            function_name = function_info.get("thread")
            function_size = function_info.get("size")
            try:
                logger.info(f"[+] Analyzing {function_name}")
                function = parser.find_function(function_name)
                result = parser.bfs(function)
                print(result)
                function_results.append(
                    {
                        "name": function_name,
                        "source_size": function_size,
                        "biggest_stack": result["biggest_stack"],
                        "deepest_stack": result["deepest_stack"],
                        "max_depth": result["max_depth"],
                        "biggest_path": result["biggest_path"],
                    }
                )

            except:
                logger.warning(f"[-] Analyze Failed: {function_name}")
                function_results.append(
                    {
                        "name": function_name,
                        "source_size": function_size,
                        "biggest_stack": -1,
                        "deepest_stack": -1,
                        "max_depth": -1,
                        "biggest_path": [],
                    }
                )
        self.function_results = function_results
        logger.debug(f"[+] ================ Analyze End ================")
        return function_results

    def dump_result(self) -> list[dict]:
        # get absolute path
        return self.function_results
