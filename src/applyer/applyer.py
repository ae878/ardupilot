from config.config import ConfigFactory
import os
import re


class FileItem:
    def __init__(self, file_path: str, line_number: int, content: str):
        self.file_path = file_path
        self.line_number = line_number
        self.content = content


class Applyer:
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

    def apply(self, config: ConfigFactory, target_macros: list[str] = []):
        """
        Apply config into the project

        Args:
            config (ConfigFactory): The config to apply.
            target_macros (list[str]): List of macro names to apply. If empty, apply all macros.
        """
        # Walk through the base directory
        for root, _, files in os.walk(self.base):
            for file in files:
                # Check if file has valid extension
                if not any(file.endswith(ext) for ext in self.apply_extensions):
                    continue

                file_path = os.path.join(root, file)
                self._process_file(file_path, config, target_macros)

    def _process_file(self, file_path: str, config: ConfigFactory, target_macros: list[str]):
        """
        Process single file and apply changes

        Args:
            file_path (str): Path to the file
            config (ConfigFactory): Config factory instance
            target_macros (list[str]): List of target macros
        """
        with open(file_path, "r") as f:
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
                # Create new define line with updated value, preserving original spacing
                leading_space = re.match(r"^\s*", line).group()
                new_line = f"{leading_space}#define {macro_name:<24} {macro_config.value}\n"
                modified_lines[i - 1] = new_line
                # Store applied change
                self.apply_items.append(FileItem(file_path, i, new_line))
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
        pass
