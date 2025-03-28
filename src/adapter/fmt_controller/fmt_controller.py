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


class FMTControllerAdapter(BaseAdapter):
    def __init__(
        self,
        base: str,
        build_commands: list[str],
        thread_functions_file_path: str = "",
        analyze_result_dir="./analyze_fmtcontroller",
        verbose: bool = False,
        build_base: str = "",
    ):
        """
        FMTControllerAdapter class
        This class is used to build and analyze the project.

        Args:
            base (str): The base directory of the project.
            build_commands (list[str]): The build commands to build the Wideband project.
            config_file_src (str): The source file of the FMT-Controller project configuration file.
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
        # Build base
        self.build_base = build_base

        self.name = "fmt-controller"

        with open(self.thread_functions_file_path, "r", encoding="utf-8") as file:
            self.thread_functions = json.load(file)

        # TODO: initial build and get build commands
        self.build_commands = []

        # build_includes.txt 파일의 절대 경로 생성
        current_dir = os.path.dirname(os.path.abspath(__file__))
        build_commands_path = os.path.join(current_dir, "build_commands.txt")
        with open(build_commands_path, "r", encoding="utf-8") as file:
            self.build_commands = file.readlines()

    def build(self, config: Union[ConfigFactory, str, None] = None) -> bool:
        # if config is None:
        #     raise BuildErrorException("ConfigFactory is None")
        if self.verbose:
            logger.info("[bold cyan]================ Build Start ================")

        # config를 config.h 파일로 생성
        original_cwd = os.getcwd()

        # 현재 디렉토리의 target/amov/icf5 디렉토리로 이동
        build_dir = os.path.join(self.base, "target", "amov", "icf5")
        os.chdir(build_dir)
        logger.info(f"[yellow]Changed working directory to: {build_dir}")

        with Progress(
            SpinnerColumn(),
            TextColumn("[progress.description]{task.description}"),
            BarColumn(),
            TaskProgressColumn(),
            console=console,
        ) as progress:
            # Create main build task
            build_task = progress.add_task("[cyan]Building...", total=len(self.build_commands))

            # Build
            for i, build_command in enumerate(self.build_commands, 1):
                build_command_list = build_command.strip().split(" ")
                # for idx, build_command_item in enumerate(build_command_list):
                #     if build_command_item.startswith("-I") and (not build_command_list[idx + 1].startswith("-I")):
                #         # -I 다음에 -I가 아닌 다른 flag가 오면 config_file을 추가
                #         build_command_list.insert(idx + 1, f"-include")
                #         build_command_list.insert(idx + 2, config_file)
                #         break
                # Update progress description with current command
                progress.update(build_task, description=f"[cyan]Building ({i}/{len(self.build_commands)})")

                try:
                    # Execute build command
                    result = subprocess.run(build_command_list, check=True, capture_output=True, text=True)

                    if self.verbose:
                        # Log command output if verbose
                        if result.stdout:
                            logger.debug(f"[dim]{result.stdout}")

                except subprocess.CalledProcessError as e:
                    logger.error(f"[red]Build command failed: {' '.join(build_command_list)}")
                    if e.stdout:
                        logger.error(f"[red]stdout: {e.stdout}")
                    if e.stderr:
                        logger.error(f"[red]stderr: {e.stderr}")
                    raise BuildErrorException(f"Build failed: {str(e)}")
                except Exception as e:
                    logger.error(f"[red]Unexpected error during build: {str(e)}")
                    raise e

                progress.advance(build_task)

        # Restore cwd
        os.chdir(original_cwd)
        logger.info("[bold cyan]================ Build End ================")

        return True
