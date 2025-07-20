"""
When you build system, add flag -E -dM into gcc and it emits define macros.
This script resolves macros defined in .o files, and returns a JSON file with resolved values.
This is for making seed configruation
"""

import os
import re
from collections import deque
import sys

sys.set_int_max_str_digits(100000)


def clean_number_suffix_in_expr(expr):
    def clean_token(token):
        token = token.replace("'", "")

        if re.fullmatch(r"\d+\.\d+[fF]", token):
            return token[:-1]

        if re.fullmatch(r"0[xX][0-9a-fA-F]+[uUlL]*", token):
            return re.sub(r"[uUlL]+$", "", token)

        if re.fullmatch(r"\d+[uUlL]*", token):
            return re.sub(r"[uUlL]+$", "", token)

        return token

    tokens = re.findall(r"\b\w+\.?\w*\b", expr)
    for t in tokens:
        cleaned = clean_token(t)
        if cleaned != t:
            expr = re.sub(rf"\b{re.escape(t)}\b", cleaned, expr)
    return expr


# C 스타일 cast만 제거하되, 숫자 괄호식 (e.g., (6U))는 보존
def remove_c_casts(val):
    return re.sub(r"\(\s*[a-zA-Z_][\w\s\*]*\s*\)", "", val)


# 의존성 찾기
def extract_dependencies(expr, macro_names):
    tokens = re.findall(r"\b\w+\b", expr)
    return [t for t in tokens if t in macro_names and t != expr]


# 치환 및 계산
def resolve_macros_bfs_repeat(macros, max_rounds=10):
    resolved = {}
    unresolved = dict(macros)

    for _ in range(max_rounds):  # 최대 반복 횟수 제한
        progress = False
        deps = {k: set(extract_dependencies(v, macros.keys())) for k, v in unresolved.items()}
        queue = deque([k for k, d in deps.items() if d <= resolved.keys()])

        while queue:
            curr = queue.popleft()
            # print(f"Resolving: {curr} = {unresolved[curr]}")
            expr = unresolved[curr]
            expr = clean_number_suffix_in_expr(expr)
            expr = remove_c_casts(expr)

            tokens = re.findall(r"\b\w+\b", expr)
            for t in tokens:
                if t in resolved:
                    expr = re.sub(rf"\b{t}\b", str(resolved[t]), expr)
            if curr == "TIM_CCMR2_IC4F_Msk":
                if "TIM_CCMR2_IC4F_Pos" in resolved:
                    print(resolved["TIM_CCMR2_IC4F_Pos"])
                print(unresolved[curr])
                print(curr)
                print(expr)
                try:
                    print(eval(expr))
                except:
                    pass

            try:
                val = eval(expr, {"__builtins__": {}})
                resolved[curr] = val
                del unresolved[curr]
                progress = True
            except:
                continue

        if not progress:
            break  # 더 이상 풀 수 있는 게 없으면 종료

    # 남은 unresolved는 계산 실패한 매크로
    resolved.update(unresolved)
    return resolved


# 매크로 파일 수집 (.o에 매크로가 텍스트로 들어있는 경우)
def collect_macros_from_o_files(directory):
    macros = {}
    define_re = re.compile(r"#define\s+(\w+)\s+(.*)")

    for root, _, files in os.walk(directory):
        for fname in files:
            if fname.endswith(".o"):
                file_path = os.path.join(root, fname)
                with open(file_path, "r", encoding="utf-8") as f:
                    for line in f:
                        match = define_re.match(line.strip())
                        if match:
                            name, value = match.groups()
                            macros[name] = value.strip()
    return macros


# main 함수
def main():
    directory = "./"  # 여기에 .o 텍스트 파일들 넣어
    macros = collect_macros_from_o_files(directory)
    resolved = resolve_macros_bfs_repeat(macros)

    def convert_sets(obj):
        if isinstance(obj, dict):
            return {k: convert_sets(v) for k, v in obj.items()}
        elif isinstance(obj, set):
            return [convert_sets(v) for v in obj]
        elif isinstance(obj, (list, tuple)):
            return [convert_sets(v) for v in obj]
        else:
            return obj

    resolved = convert_sets(resolved)
    with open("resolved.json", "w") as f:
        import json

        json.dump(resolved, f, indent=4)
    # for k in sorted(resolved):
    #     print(f"{k} = {resolved[k]}")


if __name__ == "__main__":
    main()
