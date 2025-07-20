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
        thread_functions_file_path: str = "",
        analyze_result_dir="./analyze_wideband",
        verbose: bool = False,
        build_base: str = "",
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

        self.build_base = build_base

        self.name = "wideband"

        # build_includes.txt 파일의 절대 경로 생성
        current_dir = os.path.dirname(os.path.abspath(__file__))

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
        print(f"[+] Building Wideband project in {os.getcwd()}")

        # Run the build commands
        # board_name = config.get_config("BOARD").get("value")

        # Call make command with export board name
        # ifeq ($(BOARD),)
        # BOARD = f0_module
        # endif
        # make env
        try:
            subprocess.run(["make", "-j4", "BOARDS=f1_dual"], check=True)
        except subprocess.CalledProcessError as e:
            logger.error(f"[-] Build failed: {e}")
            raise e
        finally:
            os.chdir(original_cwd)
        if self.verbose:
            logger.debug(f"[+] ================ Build End ================")

        return True
