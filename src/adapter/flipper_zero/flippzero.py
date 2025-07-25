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
from rich.progress import (
    Progress,
    SpinnerColumn,
    TextColumn,
    BarColumn,
    TaskProgressColumn,
)
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


class FlipperZeroAdapter(BaseAdapter):
    def __init__(
        self,
        base: str,
        build_commands: list[str],
        thread_functions_file_path: str = "",
        analyze_result_dir="./analyze_flipperzero",
        verbose: bool = False,
    ):
        """
        FlipperZeroAdapter class
        This class is used to build and analyze the project.

        Args:
            base (str): The base directory of the project.
            build_commands (list[str]): The build commands to build the project.
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

        self.name = "flipperzero"

        with open(self.thread_functions_file_path, "r", encoding="utf-8") as file:
            self.thread_functions = json.load(file)

        # Load build commands from JSON file
        current_dir = os.path.dirname(os.path.abspath(__file__))
        build_commands_path = os.path.join(current_dir, "build_commands.json")
        with open(build_commands_path, "r", encoding="utf-8") as file:
            self.build_commands = json.load(file)

    def build(self, config: Union[ConfigFactory, str, None] = None) -> bool:
        if self.verbose:
            logger.info("[bold cyan]================ Build Start ================")

        original_cwd = os.getcwd()
        build_dir = os.path.join(self.base)
        os.chdir(build_dir)

        with Progress(
            SpinnerColumn(),
            TextColumn("[progress.description]{task.description}"),
            BarColumn(),
            TaskProgressColumn(),
            console=console,
        ) as progress:
            # Create main build task
            build_task = progress.add_task(
                "[cyan]Building...", total=len(self.build_commands)
            )

            # Build each command from build_commands.json
            for i, build_command in enumerate(self.build_commands, 1):
                # Get command components
                command = build_command["command"]
                directory = build_command["directory"]
                output = build_command["output"]

                # Create output directory if it doesn't exist
                os.makedirs(os.path.dirname(output), exist_ok=True)

                # Split command into list
                build_command_list = command.split()
                if "-o" not in build_command_list:
                    build_command_list.append("-o")
                    build_command_list.append(output)

                # Update progress description
                progress.update(
                    build_task,
                    description=f"[cyan]Building {os.path.basename(output)} ({i}/{len(self.build_commands)})",
                )

                try:
                    # Execute build command
                    result = subprocess.run(
                        build_command_list,
                        check=True,
                        capture_output=True,
                        text=True,
                        cwd=directory,
                    )

                    if self.verbose:
                        # Log command output if verbose
                        if result.stdout:
                            logger.debug(f"[dim]{result.stdout}")

                except subprocess.CalledProcessError as e:
                    logger.error(
                        f"[red]Build command failed: {' '.join(build_command_list)}"
                    )
                    if e.stdout:
                        logger.error(f"[red]stdout: {e.stdout}")
                    if e.stderr:
                        logger.error(f"[red]stderr: {e.stderr}")
                    os.chdir(original_cwd)
                    raise BuildErrorException(f"Build failed: {str(e)}")
                except Exception as e:
                    logger.error(f"[red]Unexpected error during build: {str(e)}")
                    os.chdir(original_cwd)
                    raise e

                progress.advance(build_task)

        # Restore original working directory
        os.chdir(original_cwd)
        logger.info("[bold cyan]================ Build End ================")

        return True
