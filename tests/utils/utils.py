import json
import glob
from typing import Tuple


def calculate_previous_runtime(file_name: str) -> Tuple[float, int]:
    """
    Calculate total runtime from previous runs and find the last completed step.

    Returns:
        Tuple[float, int]: (total_previous_time, last_step)
            - total_previous_time: Total time spent in previous runs in seconds
            - last_step: The last completed step number
    """
    total_previous_time = 0
    last_step = -1
    meta_files = glob.glob(f"output/{file_name}_*.json_meta_results.json")

    for meta_file in meta_files:
        try:
            with open(meta_file, "r") as f:
                meta_data = json.load(f)
                total_previous_time += meta_data["total_time"]
                step_num = int(meta_file.split("_")[2].split(".")[0])
                last_step = max(last_step, step_num)
        except Exception as e:
            print(f"Error reading {meta_file}: {e}")

    return total_previous_time, last_step
