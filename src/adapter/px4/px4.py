import os
import os.path
import logging
import subprocess
import copy
import csv
import json
from typing import Literal, Union
from src.utils.logging import logging as logger, console
from src.utils.exception import BuildErrorException
from src.adapter.adapter import BaseAdapter
from src.config.config import ConfigFactory
from rich.progress import Progress, SpinnerColumn, TextColumn, BarColumn, TaskProgressColumn


class PX4Adapter(BaseAdapter):
    def __init__(
        self,
        base: str,
        build_commands: list[str],
        thread_functions_file_path: str = "",
        analyze_result_dir: str = "./analyze_px4",
        verbose: bool = False,
        build_base: str = "",
    ):
        """
        PX4Adapter class
        This class is generally used to build the project using make command.

        Args:
            base (str): The base directory of the project.
            build_commands (list[str]): The build commands to build the project.
            config_file_src (str): The source file of the project configuration file.
            thread_functions_file_path (str): The path to the thread functions file.
            analyze_result_dir (str): The directory to save the analyze result.
            verbose (bool): The verbose mode.
        """
        super().__init__(base, build_commands, thread_functions_file_path, analyze_result_dir, verbose, build_base)
        self.base = base
        # Compile commands
        self.build_commands = build_commands
        # Thread functions file path
        self.thread_functions_file_path = thread_functions_file_path
        # Build includes
        self.build_includes = []
        # Verbose mode
        self.verbose = verbose
        # Analyze result directory
        self.analyze_result_dir = analyze_result_dir
        # Thread functions
        self.thread_functions = []
        # Function results
        self.function_results = []
        # Build base
        self.build_base = build_base

        self.name = "px4"

        # build_includes.txt 파일의 절대 경로 생성
        current_dir = os.path.dirname(os.path.abspath(__file__))

        with open(self.thread_functions_file_path, "r", encoding="utf-8") as file:
            self.thread_functions = json.load(file)

        if not os.path.exists(os.path.join(self.build_base, "Makefile")):
            raise BuildErrorException(f"Makefile not found in {self.build_base}")

    def build(self, config: Union[ConfigFactory, str, None] = None, additional_args: list[str] = []) -> bool:
        if self.verbose:
            logger.debug(f"[+] ================ Build Start ================")
        original_cwd = os.getcwd()
        # Change the cwd to the base directory

        os.chdir(self.base)

        # Run as subprocess
        subprocess.run(["make", *additional_args], check=True)

        os.chdir(original_cwd)
        if self.verbose:
            logger.debug(f"[+] ================ Build End ================")
        return True
