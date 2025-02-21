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


class ArdupilotAdapter(BaseAdapter):
    def __init__(
        self,
        base: str,
        build_commands: list[str],
        thread_functions_file_path: str = "",
        analyze_result_dir: str = "./analyze_ardupilot",
        verbose: bool = False,
    ):
        """
        ArdupilotAdapter class
        This class is used to build and analyze the Ardupilot project.

        Args:
            base (str): The base directory of the Ardupilot project.
            build_commands (list[str]): The build commands to build the Ardupilot project.
            config_file_src (str): The source file of the Ardupilot project configuration file.
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

        self.name = "ardupilot"

        # build_includes.txt 파일의 절대 경로 생성
        current_dir = os.path.dirname(os.path.abspath(__file__))
        build_includes_path = os.path.join(current_dir, "build_includes.txt")

        with open(build_includes_path, "r", encoding="utf-8") as file:
            include_flags = file.readlines()
            self.build_includes = [flag.strip() for flag in include_flags if flag.strip()]

        with open(self.thread_functions_file_path, "r", encoding="utf-8") as file:
            self.thread_functions = json.load(file)

        # Build cache to store last modified times
        self.build_cache = {}

    def _should_rebuild(self, output_file: str, command: list[str]) -> bool:
        """
        Check if rebuilding is necessary by comparing source and object file timestamps
        """
        # If output doesn't exist, rebuild is needed
        if not os.path.exists(output_file):
            return True

        # Find source file from command (usually the last argument)
        source_file = command[-1]
        if not os.path.exists(source_file):
            return True

        # Check if source was modified after the output was created
        source_mtime = os.path.getmtime(source_file)
        output_mtime = os.path.getmtime(output_file)

        # Check dependencies if .d file exists
        dep_file = output_file + ".d"
        if os.path.exists(dep_file):
            with open(dep_file, "r") as f:
                # Parse dependency file
                deps = f.read().replace("\\\n", "").split(":")[1].split()
                for dep in deps:
                    if os.path.exists(dep):
                        dep_mtime = os.path.getmtime(dep)
                        if dep_mtime > output_mtime:
                            return True

        return source_mtime > output_mtime

    def build(self, config: Union[ConfigFactory, str, None] = None) -> bool:
        if self.verbose:
            logger.debug("[+] ================ Build Start ================")
        original_cwd = os.getcwd()
        os.chdir(self.base)

        with Progress(
            SpinnerColumn(),
            TextColumn("[cyan]Building..."),
            BarColumn(),
            TaskProgressColumn(),
            console=console,
        ) as progress:
            task = progress.add_task("[cyan]Building...", total=len(self.build_commands))

            for build_command in self.build_commands:
                compile_arguments = copy.deepcopy(build_command)
                output_file = ""

                # Find output file path
                for i, argument in enumerate(compile_arguments):
                    if argument.startswith("-o"):
                        if argument == "-o":
                            output_file = compile_arguments[i + 1]
                        else:
                            output_file = argument[2:]
                        break

                # Add -MMD flag if not present to generate dependency files
                if "-MMD" not in compile_arguments:
                    # Find the source file (last argument) and insert -MMD before it
                    source_file_index = len(compile_arguments) - 1
                    compile_arguments.insert(source_file_index, "-MMD")

                output_directory = os.path.dirname(output_file)
                os.makedirs(output_directory, exist_ok=True)

                # Check if rebuild is necessary
                if not self._should_rebuild(output_file, compile_arguments):
                    if self.verbose:
                        logger.debug(f"[+] Skipping up-to-date file: {output_file}")
                    progress.update(task, advance=1)
                    continue

                if self.verbose:
                    logger.debug(f"[+] Directory: {output_directory}")
                    logger.debug(f"[+] Command: {compile_arguments}")

                try:
                    result = subprocess.run(
                        compile_arguments,
                        check=True,
                        text=True,
                        capture_output=True,
                        cwd=self.base,
                    )
                    if result.returncode == -1:
                        logger.error(f"[-] Command failed: {compile_arguments}")
                        raise BuildErrorException(f"Command failed: {compile_arguments}")
                except subprocess.CalledProcessError:
                    logger.error(f"[-] Command failed: {compile_arguments}")
                    raise BuildErrorException(f"Command failed: {compile_arguments}")
                finally:
                    progress.update(task, advance=1)

        os.chdir(original_cwd)
        if self.verbose:
            logger.debug("[+] ================ Build End ================")
        return True
