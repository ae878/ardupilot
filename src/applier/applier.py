from src.ir2dot.irlib.function import Function
from src.ir2dot.irlib.file import File
from src.config.config import Config, ConfigFactory
from src.utils.logging import logging as logger
from typing import Union
import os
import re
from rich.progress import Progress, SpinnerColumn, TextColumn, BarColumn, TaskProgressColumn


class FileItem:
    def __init__(self, file_path: str, line_number: int, content: str):
        self.file_path = file_path
        self.line_number = line_number
        self.content = content


class Applier:
    def __init__(self, base: str, apply_extensions: list[str] = [".c", ".h", ".cpp", ".hpp"]):
        """
        Applyer class
        This class is used to apply the changes to the files.

        Args:
            base (str): The base directory of the project.
            apply_extensions (list[str]): The extensions of the files to apply the changes.
        """
        self.base = base
        self.apply_extensions = apply_extensions

        self.original_items = []
        self.apply_items = []

    def apply(self, config: ConfigFactory, target_macros: list[Union[str, Config]] = []):
        """
        Apply config into the project

        Args:
            config (ConfigFactory): The config to apply.
            target_macros (list[str]): List of macro names to apply. If empty, apply all macros.
            related_files_per_function (dict[str, set[File]]): The files that are related to the target macros.
        """
        # Get total number of files to process
        file_paths = []
        total_files = 0
        # total_files = sum(
        #     1
        #     for root, _, files in os.walk(self.base)
        #     for file in files
        #     if any(file.endswith(ext) for ext in self.apply_extensions)
        # )

        # If target_macros are used, find all files that use the macro
        if len(target_macros) > 0:

            total_files_set = set()
            for target_macro in target_macros:
                # Find macro in ConfigFactory, add files in macro_config.used_in
                if isinstance(target_macro, str):
                    macro_config = config.get_config(target_macro)
                else:
                    macro_config = target_macro
                for file_path in macro_config.used_in:
                    total_files_set.add(file_path)
            file_paths = list(total_files_set)
        else:
            logger.debug(f"[+] ================ Apply All Macros ================")
            for root, _, files in os.walk(self.base):
                for file in files:
                    if not any(file.endswith(ext) for ext in self.apply_extensions):
                        continue
                    file_paths.append(os.path.join(root, file))

        total_files = len(file_paths)
        with Progress(
            SpinnerColumn(),
            TextColumn("[progress.description]{task.description}"),
            BarColumn(),
            TaskProgressColumn(),
        ) as progress:
            # Create main task
            main_task = progress.add_task("[cyan]Processing files...", total=total_files)

            # Walk through the base directory
            for file_path in file_paths:
                # Update progress description with current file
                progress.update(main_task, description=f"[cyan]Processing {os.path.basename(file_path)}")
                try:
                    self._apply_file(file_path, config, target_macros)
                except Exception as e:
                    logger.error(f"Error applying file {file_path}: {str(e)}")
                progress.advance(main_task)

    def _apply_file(self, file_path: str, config: ConfigFactory, target_macros: list[str]):
        """
        Process single file and apply changes

        Args:
            file_path (str): Path to the file
            config (ConfigFactory): Config factory instance
            target_macros (list[str]): List of target macros
        """
        with open(file_path, "r", encoding="utf-8", errors="ignore") as f:
            lines = f.readlines()

        modified_lines = lines.copy()
        # 정규식 패턴: #define으로 시작하고, 하나 이상의 공백, 매크로 이름, 하나 이상의 공백, 값으로 구성
        define_pattern = re.compile(r"^\s*#define\s+(\w+)\s+(.+?)\s*$")

        for i, line in enumerate(lines, 1):
            # Store original line
            self.original_items.append(FileItem(file_path, i, line))

            # Check if line contains #define using regex
            match = define_pattern.match(line.strip())
            if not match:
                continue

            macro_name = match.group(1)

            # Skip if macro is not in target_macros (when target_macros is not empty)
            if target_macros and macro_name not in target_macros:
                continue

            try:
                # Get config for macro
                macro_config = config.get_config(macro_name)
                if not macro_config or not macro_config.value:
                    continue

                # Create new define line with updated value, preserving original spacing
                leading_space = re.match(r"^\s*", line)
                if leading_space:  # None 체크 추가
                    leading_space = leading_space.group()
                else:
                    leading_space = ""
                new_line = f"{leading_space}#define {macro_name:<24} {macro_config.value}\n"
                modified_lines[i - 1] = new_line
                # Store applied change
                self.apply_items.append(FileItem(file_path, i, new_line))
                logger.debug(f"[+] Applied {file_path}:{i} {macro_name} {macro_config.value}")
            except Exception:
                # Skip if macro not found in config
                continue

        # Write modified content back to file
        with open(file_path, "w") as f:
            f.writelines(modified_lines)

    def revert(self):
        """
        Revert the changes to the original files.
        """
        # 파일별로 변경사항을 그룹화
        file_changes = {}
        for item in self.original_items:
            if item.file_path not in file_changes:
                file_changes[item.file_path] = {}
            file_changes[item.file_path][item.line_number] = item.content

        # 각 파일에 대해 원본 내용으로 되돌리기
        for file_path, changes in file_changes.items():
            try:
                # 파일 읽기
                with open(file_path, "r", encoding="utf-8", errors="ignore") as f:
                    lines = f.readlines()

                # 변경된 줄 되돌리기
                for line_number, original_content in changes.items():
                    lines[line_number - 1] = original_content

                # 파일 쓰기
                with open(file_path, "w") as f:
                    f.writelines(lines)

            except Exception as e:
                print(f"Error reverting file {file_path}: {str(e)}")

        # 변경 이력 초기화
        self.original_items.clear()
        self.apply_items.clear()
