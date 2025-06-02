import json

with open("./macros.json", "r", encoding="utf-8") as f:
    macros = json.load(f)

with open("./macros_format.json", "w", encoding="utf-8") as f:
    json.dump(macros, f, ensure_ascii=False, indent=2)
