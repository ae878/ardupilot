import os
import os.path

import subprocess
import copy
import csv
import json
from typing import Literal, Union
from src.utils.logging import logging as logger, console
from src.config.config import ConfigFactory
from src.utils.exception import BuildErrorException
from src.adapter.adapter import BaseAdapter
from rich.progress import Progress, SpinnerColumn, TextColumn, BarColumn, TaskProgressColumn
from rich.console import Console
from rich.logging import RichHandler


class SampleAdapter(BaseAdapter):
    def __init__(
        self,
        base: str,
        build_commands: list[str],
        thread_functions_file_path: str = "",
        analyze_result_dir="./analyze_fmtcontroller",
        verbose: bool = False,
    ):
        """
        The sample adapter for Sample project
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

        self.name = "sample"

        with open(self.thread_functions_file_path, "r", encoding="utf-8") as file:
            self.thread_functions = json.load(file)

    def build(self, config: Union[ConfigFactory, str, None] = None) -> bool:
        if not isinstance(config, ConfigFactory):
            raise BuildErrorException("ConfigFactory is None")
        if self.verbose:
            logger.debug(f"[+] ================ Build Start ================")
        original_cwd = os.getcwd()

        # change dir
        build_dir = self.base
        build_command = [
            "arm-none-eabi-gcc",
            "-o",
            "sample.elf",
            "sample.c",
            "-O0",
            "-g",
            "-fstack-usage",
            "-fdump-tree-optimized-graph",
        ]
        os.chdir(build_dir)

        logger.info(f"[yellow]Changed working directory to: {build_dir}")
        try:
            subprocess.run(build_command, check=True)
        except subprocess.CalledProcessError as e:
            raise BuildErrorException(f"Build failed: {e}")
        finally:
            os.chdir(original_cwd)
        if self.verbose:
            logger.debug(f"[+] ================ Build End ================")
        return True
