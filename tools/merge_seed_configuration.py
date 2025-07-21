import json
import sys

sys.setrecursionlimit(100000)
sys.set_int_max_str_digits(1000000)

macros = {}
seed_configs = {}
with open("./macros.json", "r", encoding="utf-8") as f:
    macros = json.load(f)

with open("./test.json", "r", encoding="utf-8") as f:
    seed_configs = json.load(f)


for macro in macros.keys():
    if macro in seed_configs:
        original_value = macros[macro]["value"]
        macro_value = seed_configs[macro]
        if type(macro_value) is int or type(macro_value) is float:
            print(f"Change macro {macro} from {original_value} to {seed_configs[macro]}")
            macros[macro]["value"] = macro_value

with open("./macros_out.json", "w", encoding="utf-8") as f:
    json.dump(macros, f, indent=2)
