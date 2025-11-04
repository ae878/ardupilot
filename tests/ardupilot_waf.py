#!/usr/bin/env python3


import os
import json
import subprocess
import time
import random
import signal
import sys
import argparse
from datetime import datetime, timedelta
import shutil
import glob
import hashlib
from collections import defaultdict
import re
import copy


sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from src.ir2dot.gccir2dot import Parser


class FuzzerStep:
    def __init__(
        self,
        build_result: bool,
        function_results: list,
        step: int,
        config: dict,
        start_time: float,
        apply_time: float,
        build_time: float,
        analyze_time: float,
        end_time: float,
        unique_stack_smash_count: int,
    ):
        self.build_result = build_result
        self.function_results = function_results
        self.step = step
        self.config = copy.deepcopy(config)
        self.start_time = start_time
        self.apply_time = apply_time
        self.build_time = build_time
        self.analyze_time = analyze_time
        self.end_time = end_time
        self.unique_stack_smash_count = unique_stack_smash_count

    def dump_result_to_file(self, output_base_filename: str):
        function_file_name = f"{output_base_filename}_function_results.json"
        config_file_name = f"{output_base_filename}_config_results.json"
        meta_file_name = f"{output_base_filename}_meta_results.json"

        os.makedirs(os.path.dirname(output_base_filename) if os.path.dirname(output_base_filename) else ".", exist_ok=True)

        with open(function_file_name, "w") as f:
            json.dump(self.function_results, f, indent=2)

        with open(config_file_name, "w") as f:
            json.dump(self.config, f, indent=2)

        with open(meta_file_name, "w") as f:
            json.dump(
                {
                    "build_result": self.build_result,
                    "start_time": self.start_time,
                    "apply_time": self.apply_time,
                    "build_time": self.build_time,
                    "analyze_time": self.analyze_time,
                    "end_time": self.end_time,
                    "total_time": self.end_time - self.start_time,
                    "unique_stack_smash_count": self.unique_stack_smash_count,
                },
                f,
                indent=2
            )


class ConfigFuzzWafRunnerV3:
    def __init__(self, timeout_seconds=3600, use_cache=True, stack_threshold=512, resume_from=None):
        self.start_time = time.time()
        self.timeout = timeout_seconds
        self.use_cache = use_cache
        self.stack_threshold = stack_threshold
        self.test_count = 0
        self.success_count = 0
        self.fail_count = 0
        self.cache_hits = 0
        self.running = True
        self.resumed_session = False
        self.original_start_time = self.start_time

        # 스택 변화 추적
        self.baseline_stack_map = {}
        self.stack_changes_count = 0
        self.significant_changes = []
        self.unique_stack_smash_count = 0
        self.unique_stack_smashes = set()

        # 경로 설정
        self.configfuzz_path = "/conffuzz"
        self.ardupilot_path = "/home/ubuntu/lab/ardupilot"
        self.build_dir = os.path.join(self.ardupilot_path, "build/AIRLink")
        self.build_base = self.build_dir

        # ConfigFuzz 호환을 위한 adapter 이름
        self.adapter_name = "ardupilot"

        # ConfigFuzz 호환을 위한 thread functions
        self.thread_functions_file_path = "src/adapter/ardupilot/thread_functions.json"
        self.target_thread_functions = []

        # 작업 디렉토리 설정
        os.chdir(self.configfuzz_path)

        # Resume 처리
        if resume_from:
            self.resume_session(resume_from)
        else:
            self.init_new_session()

        # 매크로 캐시
        self.macro_cache = {}
        if self.use_cache:
            self.load_cache()

        # 매크로 로드
        self.load_macros()

        # ConfigFuzz 호환을 위한 thread functions 로드
        self.load_thread_functions()

        # Signal handler
        signal.signal(signal.SIGINT, self.signal_handler)
        signal.signal(signal.SIGTERM, self.signal_handler)

        # 원본과 동일하게 최근 10개 스텝 저장
        self.max_recent_steps = 10
        self.recent_steps = []
        self.recent_step = None

        # 시작 메시지
        self.print_header()

    def load_thread_functions(self):
        try:
            thread_functions_path = os.path.join(self.configfuzz_path, self.thread_functions_file_path)
            if os.path.exists(thread_functions_path):
                with open(thread_functions_path, 'r') as f:
                    datas = json.load(f)
                    for data in datas:
                        self.target_thread_functions.append(data["thread"])
        except Exception as e:
            self.log(f"Warning: Could not load thread functions: {e}")
            # 파일이 없으면 기본값 사용
            self.target_thread_functions = ["APM_thread", "main_thread"]

    def resume_session(self, resume_dir):
        """이전 세션 재개"""
        if not os.path.isabs(resume_dir):
            if os.path.exists(os.path.join(self.configfuzz_path, resume_dir)):
                resume_path = os.path.join(self.configfuzz_path, resume_dir)
            elif os.path.exists(resume_dir):
                resume_path = resume_dir
            else:
                print(f"ERROR: Resume directory not found: {resume_dir}")
                sys.exit(1)
        else:
            resume_path = resume_dir

        if not os.path.exists(resume_path):
            print(f"ERROR: Resume directory does not exist: {resume_path}")
            sys.exit(1)

        print(f"Resuming from: {resume_path}")
        self.resumed_session = True

        # 이전 세션 상태 로드
        state_file = os.path.join(resume_path, "session_state.json")
        if os.path.exists(state_file):
            with open(state_file, 'r') as f:
                state = json.load(f)
                self.test_count = state.get("test_count", 0)
                self.success_count = state.get("success_count", 0)
                self.fail_count = state.get("fail_count", 0)
                self.cache_hits = state.get("cache_hits", 0)
                self.original_start_time = state.get("original_start_time", self.start_time)
                self.baseline_stack_map = state.get("baseline_stack_map", {})
                self.stack_changes_count = state.get("stack_changes_count", 0)
                self.significant_changes = state.get("significant_changes", [])
                self.unique_stack_smash_count = state.get("unique_stack_smash_count", 0)
                elapsed_time = state.get("elapsed_time", 0)

                if self.timeout == 3600:  # 기본값이면
                    self.timeout = max(3600 - elapsed_time, 60)

                print(f"Loaded state: {self.test_count} tests completed, {self.success_count} successful")
                print(f"Remaining time: {self.format_duration(self.timeout)}")

        # 기존 출력 디렉토리 사용
        self.output_dir_name = os.path.basename(resume_path)
        self.output_dir = resume_path
        self.output_base_dir = "output"  # ConfigFuzz 호환성을 위해

        # 필요한 서브디렉토리 생성
        os.makedirs(os.path.join(self.output_dir, "configs"), exist_ok=True)
        os.makedirs(os.path.join(self.output_dir, "logs"), exist_ok=True)
        os.makedirs(os.path.join(self.output_dir, "results"), exist_ok=True)
        os.makedirs(os.path.join(self.output_dir, "stack_analysis"), exist_ok=True)

        # 로그 파일 append 모드로 열기
        self.main_log_path = f"{self.output_dir}/main.log"
        self.main_log = open(self.main_log_path, "a")
        self.log("\n" + "="*60)
        self.log(f"SESSION RESUMED at {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
        self.log("="*60)

    def init_new_session(self):
        """새 세션 초기화"""
        self.output_dir_name = f"output_waf_v3_{datetime.now().strftime('%Y%m%d_%H%M%S')}"
        self.output_dir = os.path.join(self.configfuzz_path, self.output_dir_name)
        self.output_base_dir = "output"  # ConfigFuzz 호환성을 위해

        os.makedirs(self.output_dir, exist_ok=True)
        os.makedirs(os.path.join(self.output_dir, "configs"), exist_ok=True)
        os.makedirs(os.path.join(self.output_dir, "logs"), exist_ok=True)
        os.makedirs(os.path.join(self.output_dir, "results"), exist_ok=True)
        os.makedirs(os.path.join(self.output_dir, "stack_analysis"), exist_ok=True)

        # ConfigFuzz 호환을 위한 output 심볼릭 링크 생성
        output_link = os.path.join(self.configfuzz_path, "output")
        if os.path.islink(output_link):
            os.unlink(output_link)
        elif os.path.exists(output_link):
            shutil.rmtree(output_link)
        os.symlink(self.output_dir, output_link)

        # 로그 파일
        self.main_log_path = f"{self.output_dir}/main.log"
        self.main_log = open(self.main_log_path, "w")

    def save_session_state(self):
        """현재 세션 상태 저장"""
        state = {
            "test_count": self.test_count,
            "success_count": self.success_count,
            "fail_count": self.fail_count,
            "cache_hits": self.cache_hits,
            "original_start_time": self.original_start_time,
            "elapsed_time": time.time() - self.original_start_time,
            "baseline_stack_map": self.baseline_stack_map,
            "stack_changes_count": self.stack_changes_count,
            "significant_changes": self.significant_changes,
            "unique_stack_smash_count": self.unique_stack_smash_count,
            "last_update": datetime.now().isoformat()
        }

        state_file = os.path.join(self.output_dir, "session_state.json")
        with open(state_file, 'w') as f:
            json.dump(state, f, indent=2)

    def print_header(self):
        """헤더 정보 출력"""
        duration_str = self.format_duration(self.timeout)

        self.log("=" * 60)
        if self.resumed_session:
            self.log("ConfigFuzz + Waf Integration v3 [RESUMED SESSION]")
        else:
            self.log("ConfigFuzz + Waf Integration v3 (ConfigFuzz Compatible)")
        self.log("=" * 60)
        self.log(f"Output directory: {self.output_dir_name}")
        self.log(f"Duration: {duration_str}")
        self.log(f"Stack threshold: {self.stack_threshold} bytes")
        self.log(f"Cache: {'Enabled' if self.use_cache else 'Disabled'}")
        if self.resumed_session:
            self.log(f"Tests completed: {self.test_count}")
            self.log(f"Success rate so far: {self.success_count/self.test_count*100:.1f}%" if self.test_count > 0 else "N/A")
        self.log(f"Started at: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
        self.log(f"Will end at: {(datetime.now() + timedelta(seconds=self.timeout)).strftime('%Y-%m-%d %H:%M:%S')}")
        self.log("=" * 60)

    def format_duration(self, seconds):
        """시간을 읽기 쉬운 형식으로 변환"""
        hours = seconds // 3600
        minutes = (seconds % 3600) // 60
        secs = seconds % 60

        parts = []
        if hours > 0:
            parts.append(f"{int(hours)} hour{'s' if hours != 1 else ''}")
        if minutes > 0:
            parts.append(f"{int(minutes)} minute{'s' if minutes != 1 else ''}")
        if secs > 0 or len(parts) == 0:
            parts.append(f"{int(secs)} second{'s' if secs != 1 else ''}")

        return " ".join(parts)

    def signal_handler(self, sig, frame):
        """Ctrl+C 처리"""
        self.log("\nInterrupted by user. Saving results...")
        self.running = False
        self.save_session_state()
        self.save_final_report()
        sys.exit(0)

    def log(self, message):
        """로그 출력 및 저장"""
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        log_msg = f"[{timestamp}] {message}"
        print(log_msg)
        self.main_log.write(log_msg + "\n")
        self.main_log.flush()

    def load_cache(self):
        """캐시 로드 (현재 세션 + 다른 세션들)"""
        cache_loaded = 0

        # 현재 세션의 캐시 로드
        current_cache_file = os.path.join(self.output_dir, "macro_cache.json")
        if os.path.exists(current_cache_file):
            try:
                with open(current_cache_file, 'r') as f:
                    self.macro_cache = json.load(f)
                    cache_loaded = len(self.macro_cache)
                    self.log(f"Loaded {cache_loaded} cached results from current session")
            except Exception as e:
                self.log(f"Error loading current cache: {e}")

        # 다른 세션들의 캐시도 로드
        try:
            for dir_name in os.listdir(self.configfuzz_path):
                if dir_name.startswith("output_") and dir_name != self.output_dir_name:
                    cache_file = os.path.join(self.configfuzz_path, dir_name, "macro_cache.json")
                    if os.path.exists(cache_file):
                        with open(cache_file, 'r') as f:
                            cached = json.load(f)
                            for key, value in cached.items():
                                if key not in self.macro_cache:
                                    self.macro_cache[key] = value
                                    cache_loaded += 1

            if cache_loaded > 0:
                self.log(f"Total {len(self.macro_cache)} cached results loaded")
        except Exception as e:
            self.log(f"Cache loading error: {e}")

    def load_macros(self):
        """ConfigFuzz 매크로 로드"""
        macro_file = os.path.join(self.configfuzz_path, "src/adapter/ardupilot/macros.json")
        try:
            with open(macro_file, 'r') as f:
                self.all_macros = json.load(f)
        except Exception as e:
            self.log(f"Error loading macros: {e}")
            self.all_macros = {}

        # 안전한 매크로만 선택 (버퍼 크기 관련 매크로 우선)
        self.safe_macros = []
        priority_keywords = ['BUFLEN', 'SIZE', 'MAX', 'STACK', 'ENABLED', 'DISABLE', 'HAL_', 'AP_', 'CONFIG']

        for name, info in self.all_macros.items():
            if name != "PACKED" and isinstance(info, dict):
                if any(keyword in name for keyword in priority_keywords):
                    self.safe_macros.append(name)

        # 최대 200개로 제한
        self.safe_macros = self.safe_macros[:200]
        self.log(f"Loaded {len(self.safe_macros)} safe macros from {len(self.all_macros)} total")

    def generate_macro_combination(self):
        """매크로 조합 생성"""
        num_macros = random.randint(3, min(10, len(self.safe_macros)))
        selected_macros = random.sample(self.safe_macros, num_macros)

        macro_changes = {}
        for macro in selected_macros:
            if 'BUFLEN' in macro or 'SIZE' in macro:
                macro_changes[macro] = random.choice([64, 128, 256, 512, 1024, 2048])
            elif 'MAX' in macro:
                macro_changes[macro] = random.choice([1, 2, 4, 8, 16, 32])
            else:
                macro_changes[macro] = random.choice([0, 1])

        return macro_changes

    def create_config_dict(self, macro_changes):
        """ConfigFuzz 호환 config dictionary 생성"""
        config_dict = []

        for macro_name, value in macro_changes.items():
            # all_macros에서 매크로 정보 가져오기
            macro_info = self.all_macros.get(macro_name, {})

            config_entry = {
                "name": macro_name,
                "value": value,
                "type": macro_info.get("type", "unknown"),
                "used_in": macro_info.get("used_in", []),
                "defined_in": macro_info.get("defined_in", []),
                "line_count": macro_info.get("line_count", 0)
            }
            config_dict.append(config_entry)

        return config_dict

    def get_macro_hash(self, macro_changes):
        """매크로 조합의 해시값 생성"""
        sorted_macros = sorted(macro_changes.items())
        macro_str = json.dumps(sorted_macros)
        return hashlib.md5(macro_str.encode()).hexdigest()

    def apply_macro_changes(self, macro_changes, test_id):
        """ap_config.h에 매크로 변경사항 적용"""
        config_h = os.path.join(self.ardupilot_path, "build/AIRLink/ap_config.h")

        content = """#pragma once
/* ConfigFuzz generated configuration */

#ifndef _AP_CONFIG_H_
#define _AP_CONFIG_H_

/* Essential defines */
#define _GNU_SOURCE 1
#define WAF_BUILD 1
#define PYTHONDIR "/usr/lib/python3/dist-packages"
#define PYTHONARCHDIR "/usr/lib/python3/dist-packages"
#define __STDC_FORMAT_MACROS 1
#define AP_SIGNED_FIRMWARE 0
#define HAVE_CMATH_ISFINITE 1
#define HAVE_CMATH_ISINF 1
#define HAVE_CMATH_ISNAN 1
#define NEED_CMATH_ISFINITE_STD_NAMESPACE 1
#define NEED_CMATH_ISINF_STD_NAMESPACE 1
#define NEED_CMATH_ISNAN_STD_NAMESPACE 1

/* ConfigFuzz Test #{} */
""".format(test_id)

        for name, value in macro_changes.items():
            content += f"\n/* ConfigFuzz: {name} */\n"
            content += f"#ifdef {name}\n"
            content += f"#undef {name}\n"
            content += f"#endif\n"
            content += f"#define {name} {value}\n"

        content += "\n#endif /* _AP_CONFIG_H_ */\n"

        with open(config_h, 'w') as f:
            f.write(content)

        # 설정 파일도 저장
        config_copy = os.path.join(self.output_dir, "configs", f"test_{test_id:06d}_config.h")
        shutil.copy(config_h, config_copy)


    def create_function_results(self, high_stack_functions, stack_changes):
        results = self.analyze_with_parser()  # 앞서 넣은 Parser 기반 함수
        return results

    def analyze_with_parser(self):
        """
        thread_functions(= self.target_thread_functions) 에 들어있는 함수들만
        Parser로 콜그래프 BFS를 돌려 biggest_path까지 계산.
        """
        parser_base = self.build_base if getattr(self, "build_base", None) else getattr(self, "base", self.build_dir)


        parser = Parser(
            parser_base, "",
            self.analyze_result_dir,
            is_save_pkl=False, is_load_pkl=False, is_only_test=False
        )
        parser.parse()

        function_results = []
        for name in (self.target_thread_functions or []):
            try:
                func = parser.find_function(name)
                res = parser.bfs(func)  # res: {biggest_stack, deepest_stack, max_depth, biggest_path, ...}

                # biggest_path가 노드 객체일 수도 있으므로 이름으로 정규화
                path_list = []
                for n in res.get("biggest_path", []):
                    # n이 dict/obj면 이름 필드(예: 'name')를, 문자열이면 그대로
                    if isinstance(n, str):
                        path_list.append(n)
                    elif isinstance(n, dict) and "name" in n:
                        path_list.append(n["name"])
                    else:
                        # 다른 형태면 str로 강제
                        path_list.append(str(n))

                # source_size: thread_functions.json에 size가 있다면 그 값을, 없으면 보수적으로 biggest_stack
                src_sz = None
                for ent in getattr(self, "thread_functions", []):
                    if ent.get("thread") == name:
                        src_sz = ent.get("size")
                        break
                if src_sz is None:
                    src_sz = res.get("biggest_stack", 0)

                function_results.append({
                "name": name,
                "source_size": int(src_sz),
                "biggest_stack": int(res.get("biggest_stack", -1)),
                "deepest_stack": int(res.get("deepest_stack", -1)),
                "max_depth": int(res.get("max_depth", -1)),
                "biggest_path": path_list,
                })

            except Exception as e:
                function_results.append({
                    "name": name,
                    "source_size": -1,
                    "biggest_stack": -1,
                    "deepest_stack": -1,
                    "max_depth": -1,
                    "biggest_path": [],
                })

        self.function_results = function_results
        return function_results
    
    def analyze_stack_changes(self, current_stack_map, test_id):
        """기준 빌드 대비 스택 변화 분석"""
        stack_changes = {
            "new_functions": [],
            "removed_functions": [],
            "increased": [],
            "decreased": [],
            "unchanged": 0
        }

        # 첫 번째 성공 빌드를 기준으로 설정
        if not self.baseline_stack_map and self.success_count == 1:
            self.baseline_stack_map = current_stack_map.copy()
            self.log(f"[Test {test_id}] Set as baseline with {len(self.baseline_stack_map)} functions")
            return stack_changes

        if not self.baseline_stack_map:
            return stack_changes

        # 변화 분석
        all_functions = set(self.baseline_stack_map.keys()) | set(current_stack_map.keys())

        for func in all_functions:
            baseline_size = self.baseline_stack_map.get(func, -1)
            current_size = current_stack_map.get(func, -1)

            if baseline_size == -1:
                # 새로 추가된 함수
                stack_changes["new_functions"].append({
                    "function": func,
                    "stack_size": current_size
                })
            elif current_size == -1:
                # 제거된 함수
                stack_changes["removed_functions"].append({
                    "function": func,
                    "stack_size": baseline_size
                })
            elif current_size > baseline_size:
                # 스택 증가
                diff = current_size - baseline_size
                if diff >= 16:  # 16바이트 이상 차이만 기록
                    stack_changes["increased"].append({
                        "function": func,
                        "baseline": baseline_size,
                        "current": current_size,
                        "diff": diff
                    })
            elif current_size < baseline_size:
                # 스택 감소
                diff = baseline_size - current_size
                if diff >= 16:  # 16바이트 이상 차이만 기록
                    stack_changes["decreased"].append({
                        "function": func,
                        "baseline": baseline_size,
                        "current": current_size,
                        "diff": -diff
                    })
            else:
                stack_changes["unchanged"] += 1

        # 가장 큰 변화들을 정렬
        stack_changes["increased"].sort(key=lambda x: x['diff'], reverse=True)
        stack_changes["decreased"].sort(key=lambda x: -x['diff'], reverse=True)

        return stack_changes

    def run_waf_build(self, test_id):
        """Waf로 빌드 실행"""
        current_dir = os.getcwd()
        os.chdir(self.ardupilot_path)

        build_log = os.path.join(self.output_dir, "logs", f"test_{test_id:06d}_build.log")

        cmd = ["./waf", "build", "--target", "bin/arducopter", "-j4"]

        start_time = time.time()

        try:
            with open(build_log, 'w') as log_f:
                result = subprocess.run(
                    cmd,
                    stdout=log_f,
                    stderr=subprocess.STDOUT,
                    timeout=3000,
                    text=True
                )

            build_time = time.time() - start_time
            success = (result.returncode == 0)
            error_msg = None

            if not success:
                with open(build_log, 'r') as f:
                    lines = f.readlines()
                    for line in lines:
                        if 'error:' in line:
                            error_msg = line.strip()
                            break

        except subprocess.TimeoutExpired:
            build_time = time.time() - start_time
            success = False
            error_msg = "Build timeout (120s)"

        except Exception as e:
            build_time = time.time() - start_time
            success = False
            error_msg = str(e)

        os.chdir(current_dir)

        return success, build_time, error_msg

    def run_single_test(self):
        """단일 테스트 실행 (ConfigFuzz 호환 출력)"""
        test_id = self.test_count  # ConfigFuzz 호환을 위해 0-based 사용

        self.log(f"\n[Test {test_id}] Starting...")

        # 시간 측정
        start_time = time.time()

        # 매크로 조합 생성
        macro_changes = self.generate_macro_combination()
        self.log(f"[Test {test_id}] Generated {len(macro_changes)} macro changes")

        # 캐시 확인
        if self.use_cache:
            macro_hash = self.get_macro_hash(macro_changes)
            if macro_hash in self.macro_cache:
                self.cache_hits += 1
                cached_result = self.macro_cache[macro_hash]
                self.log(f"[Test {test_id}] Cache hit! Using previous result")

                success = cached_result['build_result']
                apply_time = start_time + 0.01
                build_time = apply_time + 0.1
                analyze_time = build_time + 0.01
                error_msg = cached_result.get('error')
                function_results = cached_result.get('function_results', [])
                unique_stack_smash_count = cached_result.get('unique_stack_smash_count', 0)

            else:
                # 설정 적용
                self.apply_macro_changes(macro_changes, test_id)
                apply_time = time.time()

                # 빌드
                success, build_duration, error_msg = self.run_waf_build(test_id)
                build_time = apply_time + build_duration

                if success:
                    # 스택 분석
                    #high_stack_functions, all_stack_map, stack_changes = self.analyze_stack_usage(test_id)
                    analyze_time = time.time()

                    # function results 생성
                    #function_results = self.create_function_results(high_stack_functions, stack_changes)
                    function_results = self.analyze_with_parser()
                    
                    # unique stack smash 계산
                    for func_result in function_results:
                        if func_result.get("stack_overflow"):
                            path_str = json.dumps(func_result["biggest_path"])
                            if path_str not in self.unique_stack_smashes:
                                self.unique_stack_smash_count += 1
                                self.unique_stack_smashes.add(path_str)

                    unique_stack_smash_count = self.unique_stack_smash_count

                    # 추가 스택 분석 결과 저장
                else:
                    analyze_time = build_time
                    function_results = []
                    unique_stack_smash_count = self.unique_stack_smash_count

                # 캐시 업데이트
                self.macro_cache[macro_hash] = {
                    'build_result': success,
                    'function_results': function_results,
                    'unique_stack_smash_count': unique_stack_smash_count,
                    'error': error_msg
                }
        else:
            # 캐시 없음
            self.apply_macro_changes(macro_changes, test_id)
            apply_time = time.time()

            success, build_duration, error_msg = self.run_waf_build(test_id)
            build_time = apply_time + build_duration

            if success:
                high_stack_functions, all_stack_map, stack_changes = self.analyze_stack_usage(test_id)
                analyze_time = time.time()
                function_results = self.create_function_results(high_stack_functions, stack_changes)

                for func_result in function_results:
                    if func_result.get("stack_overflow"):
                        path_str = json.dumps(func_result["biggest_path"])
                        if path_str not in self.unique_stack_smashes:
                            self.unique_stack_smash_count += 1
                            self.unique_stack_smashes.add(path_str)

                unique_stack_smash_count = self.unique_stack_smash_count
            else:
                analyze_time = build_time
                function_results = []
                unique_stack_smash_count = self.unique_stack_smash_count

        end_time = time.time()

        # ConfigFuzz 호환 config 생성
        config_dict = self.create_config_dict(macro_changes)

        # FuzzerStep 생성 (ConfigFuzz 호환)
        fuzzer_step = FuzzerStep(
            build_result=success,
            function_results=function_results,
            step=test_id,
            config=config_dict,
            start_time=start_time,
            apply_time=apply_time,
            build_time=build_time,
            analyze_time=analyze_time,
            end_time=end_time,
            unique_stack_smash_count=unique_stack_smash_count
        )

        # recent steps에 저장
        self.recent_step = fuzzer_step
        self.recent_steps.append(fuzzer_step)
        if len(self.recent_steps) > self.max_recent_steps:
            self.recent_steps.pop(0)

        # ConfigFuzz 형식으로 결과 저장
        output_filename = f"result_{self.adapter_name}_{test_id}.json"
        fuzzer_step.dump_result_to_file(os.path.join(self.output_dir, output_filename))

        # 호환성을 위해 output 심볼릭에도 저장
        if os.path.exists(os.path.join(self.configfuzz_path, "output")):
            fuzzer_step.dump_result_to_file(os.path.join(self.configfuzz_path, "output", output_filename))

        # 카운터 업데이트
        if success:
            self.success_count += 1
            self.log(f"[Test {test_id}] ✅ BUILD SUCCESS in {build_duration:.1f}s")

            if len(high_stack_functions) > 0:
                self.log(f"[Test {test_id}] 📊 Found {len(high_stack_functions)} high stack functions")
                for i, func in enumerate(high_stack_functions[:3]):
                    self.log(f"  {i+1}. {func['stack_size']} bytes: {func['function'][:50]}...")
        else:
            self.fail_count += 1
            self.log(f"[Test {test_id}] ❌ BUILD FAILED in {build_duration:.1f}s")
            if error_msg:
                self.log(f"[Test {test_id}] Error: {error_msg[:100]}...")

        # 저장 후에 테스트 카운트 증가 (0-based 인덱싱을 위해)
        self.test_count += 1

        return success

    def print_status(self):
        """현재 상태 출력"""
        elapsed = time.time() - self.original_start_time
        remaining = self.timeout - (time.time() - self.start_time)

        self.log("\n" + "="*60)
        self.log(f"Status Update:")
        self.log(f"  Total elapsed: {self.format_duration(elapsed)}")
        self.log(f"  Session remaining: {self.format_duration(remaining)}")
        self.log(f"  Total tests: {self.test_count}")
        self.log(f"  Success: {self.success_count} ({self.success_count/self.test_count*100:.1f}%)")
        self.log(f"  Failed: {self.fail_count}")
        if self.use_cache:
            self.log(f"  Cache hits: {self.cache_hits} ({self.cache_hits/self.test_count*100:.1f}%)")
        self.log(f"  Rate: {self.test_count/(elapsed/3600):.1f} tests/hour")
        self.log(f"  Unique stack smashes: {self.unique_stack_smash_count}")
        self.log("="*60)

    def save_cache(self):
        """캐시 저장"""
        if self.use_cache:
            cache_file = os.path.join(self.output_dir, "macro_cache.json")
            with open(cache_file, 'w') as f:
                json.dump(self.macro_cache, f)

    def save_final_report(self):
        """최종 리포트 저장"""
        elapsed = time.time() - self.original_start_time

        # 세션 상태 저장
        self.save_session_state()

        # 캐시 저장
        self.save_cache()

        # 최종 리포트
        report = {
            "session_info": {
                "start_time": datetime.fromtimestamp(self.start_time).isoformat(),
                "end_time": datetime.now().isoformat(),
                "duration_seconds": elapsed,
                "duration_formatted": self.format_duration(elapsed),
                "timeout_seconds": self.timeout,
                "timeout_formatted": self.format_duration(self.timeout)
            },
            "results": {
                "total_tests": self.test_count,
                "successful_builds": self.success_count,
                "failed_builds": self.fail_count,
                "success_rate": self.success_count / self.test_count * 100 if self.test_count > 0 else 0,
                "unique_stack_smash_count": self.unique_stack_smash_count
            },
            "performance": {
                "tests_per_hour": self.test_count / (elapsed / 3600) if elapsed > 0 else 0,
                "average_build_time": elapsed / self.test_count if self.test_count > 0 else 0,
                "cache_hits": self.cache_hits if self.use_cache else 0,
                "cache_hit_rate": self.cache_hits / self.test_count * 100 if self.use_cache and self.test_count > 0 else 0
            },
            "stack_analysis": {
                "threshold": self.stack_threshold,
                "unique_stack_smashes": self.unique_stack_smash_count,
                "baseline_functions": len(self.baseline_stack_map)
            }
        }

        # JSON 리포트
        report_path = os.path.join(self.output_dir, "final_report.json")
        with open(report_path, 'w') as f:
            json.dump(report, f, indent=2)

        # 텍스트 리포트
        txt_report_path = os.path.join(self.output_dir, "final_report.txt")
        with open(txt_report_path, 'w') as f:
            f.write("ConfigFuzz + Waf Integration v3 Report\n")
            f.write("=====================================\n\n")
            f.write(f"Duration: {report['session_info']['duration_formatted']}\n")
            f.write(f"Total tests: {self.test_count}\n")
            f.write(f"Success rate: {report['results']['success_rate']:.1f}%\n")
            f.write(f"Average rate: {report['performance']['tests_per_hour']:.1f} tests/hour\n")
            f.write(f"\nSuccessful builds: {self.success_count}\n")
            f.write(f"Failed builds: {self.fail_count}\n")
            f.write(f"Unique stack smashes: {self.unique_stack_smash_count}\n")
            if self.use_cache:
                f.write(f"Cache hits: {self.cache_hits} ({report['performance']['cache_hit_rate']:.1f}%)\n")

        self.log(f"\nFinal report saved to: {self.output_dir_name}/final_report.json")

    def run(self):
        """메인 실행 루프"""
        if not self.resumed_session:
            self.log("Starting ConfigFuzz + Waf fuzzing v3 (ConfigFuzz Compatible)...")
        else:
            self.log("Resuming ConfigFuzz + Waf fuzzing v3...")

        # 초기 환경 설정
        os.chdir(self.ardupilot_path)

        # Waf configure 실행 (새 세션일 때만)
        if not self.resumed_session:
            self.log("\nRunning waf configure...")
            result = subprocess.run(["./waf", "configure", "--board", "AIRLink"],
                                  capture_output=True, text=True)
            if result.returncode != 0:
                self.log("ERROR: Waf configure failed!")
                self.log(result.stderr[:500])
                return
            self.log("Waf configure successful")
        else:
            self.log("Skipping waf configure (resumed session)")

        # 메인 루프
        try:
            while self.running and (time.time() - self.start_time) < self.timeout:
                self.run_single_test()

                # 10개마다 상태 출력
                if self.test_count % 10 == 0:
                    self.print_status()

                # 20개마다 캐시와 세션 상태 저장
                if self.test_count % 20 == 0:
                    self.save_cache()
                    self.save_session_state()

        except KeyboardInterrupt:
            self.log("\nInterrupted by user")
        except Exception as e:
            self.log(f"\nError occurred: {e}")
        finally:
            self.log(f"\nFuzzing completed! Results in: {self.output_dir_name}")
            self.log("="*60)
            self.log(f"Total: {self.test_count} tests")
            if self.test_count > 0:
                self.log(f"Success: {self.success_count} ({self.success_count/self.test_count*100:.1f}%)")
            else:
                self.log(f"Success: {self.success_count}")
            self.log(f"Failed: {self.fail_count}")
            self.log(f"Unique stack smashes: {self.unique_stack_smash_count}")
            if self.use_cache:
                self.log(f"Cache hits: {self.cache_hits}")
            self.save_final_report()
            self.main_log.close()


def main():
    parser = argparse.ArgumentParser(
        description="ConfigFuzz + Waf Integration v3 (ConfigFuzz Compatible)",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  # Start new session
  python3 configfuzz_waf_runner_v3.py --hours 6

  # Resume previous session
  python3 configfuzz_waf_runner_v3.py --resume output_waf_v3_20250812_135802 --hours 3

  # Other options
  python3 configfuzz_waf_runner_v3.py --minutes 30      # Run for 30 minutes
  python3 configfuzz_waf_runner_v3.py --no-cache        # Disable cache
  python3 configfuzz_waf_runner_v3.py --threshold 256   # Use 256 byte threshold
        """
    )

    parser.add_argument(
        "--resume",
        type=str,
        help="Resume from previous session directory"
    )

    # 시간 인자
    time_group = parser.add_mutually_exclusive_group()
    time_group.add_argument(
        "--hours",
        type=float,
        help="Duration in hours"
    )
    time_group.add_argument(
        "--minutes", "-m",
        type=float,
        help="Duration in minutes"
    )
    time_group.add_argument(
        "--seconds", "-s",
        type=int,
        help="Duration in seconds"
    )

    # 기타 인자
    parser.add_argument(
        "--no-cache",
        action="store_true",
        help="Disable macro combination caching"
    )

    parser.add_argument(
        "--threshold", "-t",
        type=int,
        default=512,
        help="Stack size threshold in bytes (default: 512)"
    )

    args = parser.parse_args()

    # 타임아웃 계산
    if args.hours:
        timeout = int(args.hours * 3600)
    elif args.minutes:
        timeout = int(args.minutes * 60)
    elif args.seconds:
        timeout = args.seconds
    else:
        timeout = 3600  # 기본값: 1시간

    # 캐시 설정
    use_cache = not args.no_cache

    # 퍼저 실행
    fuzzer = ConfigFuzzWafRunnerV3(
        timeout_seconds=timeout,
        use_cache=use_cache,
        stack_threshold=args.threshold,
        resume_from=args.resume
    )
    fuzzer.run()


if __name__ == "__main__":
    main()
