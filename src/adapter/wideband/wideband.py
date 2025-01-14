import os
import os.path
import logging
import subprocess
import copy
import csv
import json
from typing import Literal, Union
from src.config.config import ConfigFactory
from src.utils.exception import BuildErrorException
from src.adapter.adapter import BaseAdapter

logger = logging.getLogger(__name__)


def remove_duplicate_include_flags(arguments):
    seen = set()
    unique_arguments = []
    for arg in arguments:
        if arg.startswith("-I"):
            if arg not in seen:
                seen.add(arg)
                unique_arguments.append(arg)
        else:
            unique_arguments.append(arg)
    return unique_arguments


class WidebandAdapter(BaseAdapter):
    def __init__(
        self,
        base: str,
        build_commands: list[str],
        config_file_src: str = "",
        thread_functions_file_path: str = "",
        analyze_result_dir="./analyze_wideband",
        verbose: bool = False,
    ):
        """
        WidebandAdapter class
        This class is used to build and analyze the Wideband project.

        Args:
            base (str): The base directory of the Wideband project.
            build_commands (list[str]): The build commands to build the Wideband project.
            config_file_src (str): The source file of the Wideband project configuration file.
            thread_functions_file_path (str): The path to the thread functions file.
            analyze_result_dir (str): The directory to save the analyze result.
            verbose (bool): The verbose mode.
        """
        self.base = base
        # Compile commands
        self.build_commands = build_commands
        # Config file source
        self.config_file_src = config_file_src
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

        self.name = "wideband"

        # if Config file source is relative, convert it to an absolute path
        if not os.path.isabs(self.config_file_src):
            self.config_file_src = os.path.abspath(self.config_file_src)

        # build_includes.txt 파일의 절대 경로 생성
        current_dir = os.path.dirname(os.path.abspath(__file__))
        build_includes_path = os.path.join(current_dir, "build_includes.txt")

        with open(build_includes_path, "r", encoding="utf-8") as file:
            include_flags = file.readlines()
            self.build_includes = [flag.strip() for flag in include_flags if flag.strip()]

        with open(self.thread_functions_file_path, "r", encoding="utf-8") as file:
            self.thread_functions = json.load(file)

    def build(self, config: Union[ConfigFactory, str, None] = None) -> bool:
        if not isinstance(config, ConfigFactory):
            raise BuildErrorException("ConfigFactory is None")
        if self.verbose:
            logger.debug(f"[+] ================ Build Start ================")
        original_cwd = os.getcwd()
        # Change the cwd to the base directory
        os.chdir(self.base)

        # Run the build commands
        board_name = config.get_config("BOARD").get("value")

        # Call make command with export board name
        # ifeq ($(BOARD),)
        # BOARD = f0_module
        # endif
        # make env
        subprocess.run(["make", "-j4", f"BOARD={board_name}"], check=True)

        os.chdir(original_cwd)
        if self.verbose:
            logger.debug(f"[+] ================ Build End ================")
        return True
