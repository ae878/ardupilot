from abc import ABC, abstractmethod
from typing import Literal
import csv
import json
import os
from ir2dot.gccir2dot import Parser

class BaseAdapter(ABC):
    @abstractmethod
    def __init__(
        self,
        base: str,
        build_commands: list[str],
        config_file_src: str,
        thread_functions_file_path: str,
        analyze_result_dir: str,
        verbose: bool = False
    ):
        self.base = base
        self.build_commands = build_commands
        self.config_file_src = config_file_src
        self.thread_functions = []
        self.thread_functions_file_path = thread_functions_file_path
        self.analyze_result_dir = analyze_result_dir
        self.verbose = verbose

    @abstractmethod
    def build(self) -> bool:
        '''
        Batch build the script
        You can just using your own build command (such as make, cmake, etc..)
        Or just calling batch gcc commands directly

        The point is, you MUST create *.su, *.optimized, *.class files in the base directory
        '''
        pass

    # @abstractmethod
    def analyze(self):
        '''
        Analyze the project by given build result

        '''
        try:
            os.makedirs(self.analyze_result_dir, exist_ok=True)
        except Exception as e:
            pass

        # remote all files in the analyze result directory
        for file in os.listdir(self.analyze_result_dir):
            os.remove(os.path.join(self.analyze_result_dir, file))
        
        parser = Parser(
            self.base,
            "",
            self.analyze_result_dir,
            is_save_pkl = True,
            is_load_pkl = False,
            is_only_test = False
        )

        parser.parse()

        # analyze it
        function_results = []
        for function_name in self.thread_functions:
            try:
                function = parser.find_function(function_name)
                result = parser.bfs(function)
                function_results.append({
                    "name": function_name,
                    "biggest_stack": result["biggest_stack"],
                    "deepest_stack": result["deepest_stack"],
                    "max_depth": result["max_depth"],
                })

            except:
                function_results.append({
                    "name": function_name,
                    "biggest_stack": 0,
                    "deepest_stack": 0,
                    "max_depth": 0,
                })
        self.function_results = function_results
        


    def dump_result(self, save_file_name: str = "function_results", format: Literal["csv", "json"] = "csv"):
        if format == "csv":
            with open(f"{self.analyze_result_dir}/{save_file_name}.csv", "w") as f:
                writer = csv.writer(f)
                writer.writerow(["name", "biggest_stack", "deepest_stack", "max_depth"])
                for result in self.function_results:
                    writer.writerow([result["name"], result["biggest_stack"], result["deepest_stack"], result["max_depth"]])
        elif format == "json":
            with open(f"{self.analyze_result_dir}/{save_file_name}.json", "w") as f:
                json.dump(self.function_results, f, indent=4)
        else:
            raise ValueError(f"Invalid format: {format}")