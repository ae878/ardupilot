from src.config.configblockstructure import ConfigBlockStructure


class ConfigBlock:
    """
    #if 가 있을때 하나의 거대한 블록..
    #if, #elif, #else, #endif 가 하나의 큰 블록..
    여기에서 어떤걸 선택할지를 결정해야 됨
    """

    def __init__(self, scope_data: dict):
        self.file: str = scope_data.get("file", "")
        self.block_start: int = scope_data.get("block_start", 0)
        self.block_end: int = scope_data.get("block_end", 0)
        self.total_block_lines: int = scope_data.get("total_block_lines", 0)

        self.branch_type: str = scope_data.get("branch_type", "")
        self.branch_condition: str = scope_data.get("branch_condition", "")

        self.branch_start: int = scope_data.get("branch_start", 0)
        self.branch_end: int = scope_data.get("branch_end", 0)
        self.executable_lines: int = scope_data.get("executable_lines", 0)

        self.nesting_level: int = scope_data.get("nesting_level", 0)
        self.block_structure: ConfigBlockStructure = ConfigBlockStructure(scope_data.get("block_structure", {}))

    def __json__(self):
        return {
            "file": self.file,
            "block_start": self.block_start,
            "block_end": self.block_end,
            "total_block_lines": self.total_block_lines,
            "branch_type": self.branch_type,
            "branch_condition": self.branch_condition,
            "branch_start": self.branch_start,
            "branch_end": self.branch_end,
            "executable_lines": self.executable_lines,
            "nesting_level": self.nesting_level,
            "block_structure": self.block_structure.__json__(),
        }
