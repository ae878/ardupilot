import os
import os.path
import logging
import subprocess
import copy
import csv
import json
from typing import Literal
from utils.exception import BuildErrorException
from adapter.adapter import BaseAdapter


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


class ArdupilotAdapter(BaseAdapter):
    def __init__(
        self,
        base: str,
        build_commands: list[str],
        config_file_src: str,
        thread_functions_file_path: str,
        analyze_result_dir = "./analyze_ardupilot",
        verbose: bool = False,
    ):
        '''
        ArdupilotAdapter class
        This class is used to build and analyze the Ardupilot project.

        Args:
            base (str): The base directory of the Ardupilot project.
            build_commands (list[str]): The build commands to build the Ardupilot project.
            config_file_src (str): The source file of the Ardupilot project configuration file.
            thread_functions_file_path (str): The path to the thread functions file.
            analyze_result_dir (str): The directory to save the analyze result.
            verbose (bool): The verbose mode.
        '''
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


        # if Config file source is relative, convert it to an absolute path
        if not os.path.isabs(self.config_file_src):
            self.config_file_src = os.path.abspath(self.config_file_src)

        # build_includes.txt 파일의 절대 경로 생성
        current_dir = os.path.dirname(os.path.abspath(__file__))
        build_includes_path = os.path.join(current_dir, "build_includes.txt")

        with open(build_includes_path, "r", encoding="utf-8") as file:
            include_flags = file.readlines()
            self.build_includes = [
                flag.strip() for flag in include_flags if flag.strip()
            ]

        with open(self.thread_functions_file_path, "r", encoding="utf-8") as file:
            self.thread_functions = json.load(file)
    def build(self) -> bool:
        original_cwd = os.getcwd()
        # Change the cwd to the base directory
        os.chdir(self.base)

        # Run the build commands
        for build_command in self.build_commands:
            comiple_arguments = copy.deepcopy(build_command)
            output_directory = ""

            # 작업 디렉토리 확인하기
            for argument in comiple_arguments:
                if argument.startswith("-o"):
                    output_directory = argument[2:]
                    # separate the output directory from the file name
                    output_directory = os.path.dirname(output_directory)
                    break

            insert_index = next(
                (i for i, arg in enumerate(comiple_arguments) if arg.startswith("-I")),
                len(comiple_arguments),
            )
            # include_flags를 해당 인덱스 앞에 삽입
            for include_flag in self.build_includes:
                if include_flag.strip() == "":
                    continue
                comiple_arguments.insert(insert_index, include_flag)
                insert_index += 1
            comiple_arguments = remove_duplicate_include_flags(comiple_arguments)
            os.makedirs(output_directory, exist_ok=True)

            if self.verbose:
                logger.debug(f"[+] Directory: {output_directory}")
                logger.debug(f"[+] Command: {build_command}")

            try:
                result = subprocess.run(
                    comiple_arguments,
                    check=True,
                    text=True,
                    capture_output=True,
                    cwd=self.base,
                )
                if result.returncode == -1:
                    logger.error(f"[-] Command failed: {build_command}")
                    raise BuildErrorException(f"Command failed: {build_command}")
            except subprocess.CalledProcessError as e:
                logger.error(f"[-] Command failed: {build_command}")
                raise BuildErrorException(f"Command failed: {build_command}")
        os.chdir(original_cwd)
        return True



