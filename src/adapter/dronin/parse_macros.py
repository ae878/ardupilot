import json

data = []
out = []
with open("./thread_functions.json", "r") as f:
    data = json.load(f)

for thread in data:
    out.append(thread["thread"])

print(out)
