from typing import List, Dict

class ConfigBlockStructure:
    """
    특정 config가 실제로 영향받는 Scope
    """

    def __init__(self, scope_data: dict):
        self.start_line: int = scope_data.get("start_line", 0)
        self.end_line: int = scope_data.get("end_line", 0)
        self.nesting_level: int = scope_data.get("nesting_level", 0)
        self.total_lines: int = scope_data.get("total_lines", 0)
        self.branches: List[Dict] = scope_data.get("branches", [])

        self.child_blocks: List[ConfigBlockStructure] = []

        for child_block in scope_data.get("child_blocks", []):
            self.child_blocks.append(ConfigBlockStructure(child_block))

    def __json__(self):
        return {
            "start_line": self.start_line,
            "end_line": self.end_line,
            "nesting_level": self.nesting_level,
            "total_lines": self.total_lines,
            "branches": self.branches,
            "child_blocks": [child.__json__() for child in self.child_blocks],
        }

