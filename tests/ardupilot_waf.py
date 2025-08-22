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

class ConfigFuzzWafRunnerV2:
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
        self.baseline_stack_map = {}  # 기준 스택 사용량
        self.stack_changes_count = 0
        self.significant_changes = []
        
        # 경로 설정
        self.configfuzz_path = "/conffuzz"
        self.ardupilot_path = "/home/ubuntu/lab/ardupilot"
        self.build_dir = os.path.join(self.ardupilot_path, "build/AIRLink")
        
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
        
        # Signal handler
        signal.signal(signal.SIGINT, self.signal_handler)
        signal.signal(signal.SIGTERM, self.signal_handler)
        
        # 시작 메시지
        self.print_header()
        
    def resume_session(self, resume_dir):
        """이전 세션 재개"""
        # 전체 경로 구성
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
                elapsed_time = state.get("elapsed_time", 0)
                
                # 남은 시간 조정 (사용자가 명시적으로 시간을 지정하지 않으면 기본값 사용)
                if self.timeout == 3600:  # 기본값이면
                    self.timeout = max(3600 - elapsed_time, 60)  # 최소 60초
                else:
                    # 사용자가 명시적으로 지정한 경우 그대로 사용
                    pass
                
                print(f"Loaded state: {self.test_count} tests completed, {self.success_count} successful")
                print(f"Remaining time: {self.format_duration(self.timeout)}")
        else:
            print("Session state file not found, calculating from results...")
            self.calculate_stats_from_results(resume_path)
        
        # 출력 디렉토리는 기존 것을 사용
        self.output_dir_name = os.path.basename(resume_path)
        self.output_dir = resume_path
        
        # 디렉토리가 없으면 생성
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
        
    def calculate_stats_from_results(self, resume_path):
        """결과 파일들에서 통계 계산"""
        # 테스트 수 계산
        config_files = glob.glob(os.path.join(resume_path, "configs", "test_*.json"))
        self.test_count = len(config_files)
        
        # 성공/실패 수 계산
        for i in range(self.test_count):
            meta_file = os.path.join(resume_path, f"result_ardupilot_{i}.json_meta_results.json")
            if os.path.exists(meta_file):
                try:
                    with open(meta_file, 'r') as f:
                        meta = json.load(f)
                        if meta.get("build_result"):
                            self.success_count += 1
                        else:
                            self.fail_count += 1
                except:
                    pass
                    
        # main.log에서 경과 시간 추정
        log_file = os.path.join(resume_path, "main.log")
        if os.path.exists(log_file):
            try:
                with open(log_file, 'r') as f:
                    lines = f.readlines()
                    first_time = None
                    last_time = None
                    for line in lines:
                        match = re.match(r'\[(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2})\]', line)
                        if match:
                            timestamp = datetime.strptime(match.group(1), "%Y-%m-%d %H:%M:%S")
                            if first_time is None:
                                first_time = timestamp
                            last_time = timestamp
                    
                    if first_time and last_time:
                        elapsed = (last_time - first_time).total_seconds()
                        # 사용자가 명시적으로 시간을 지정하지 않으면 기본값 사용
                        if self.timeout == 3600:  # 기본값이면
                            self.timeout = max(3600 - elapsed, 60)  # 최소 60초
                        self.original_start_time = self.start_time - elapsed
            except:
                pass
                
    def init_new_session(self):
        """새 세션 초기화"""
        # 출력 디렉토리 생성
        self.output_dir_name = f"output_waf_v2_{datetime.now().strftime('%Y%m%d_%H%M%S')}"
        self.output_dir = os.path.join(self.configfuzz_path, self.output_dir_name)
        os.makedirs(self.output_dir, exist_ok=True)
        os.makedirs(os.path.join(self.output_dir, "configs"), exist_ok=True)
        os.makedirs(os.path.join(self.output_dir, "logs"), exist_ok=True)
        os.makedirs(os.path.join(self.output_dir, "results"), exist_ok=True)
        os.makedirs(os.path.join(self.output_dir, "stack_analysis"), exist_ok=True)
        
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
            self.log("ConfigFuzz + Waf Integration v2 [RESUMED SESSION]")
        else:
            self.log("ConfigFuzz + Waf Integration v2")
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
        
        # 1. 현재 세션의 캐시 로드
        current_cache_file = os.path.join(self.output_dir, "macro_cache.json")
        if os.path.exists(current_cache_file):
            try:
                with open(current_cache_file, 'r') as f:
                    self.macro_cache = json.load(f)
                    cache_loaded = len(self.macro_cache)
                    self.log(f"Loaded {cache_loaded} cached results from current session")
            except Exception as e:
                self.log(f"Error loading current cache: {e}")
        
        # 2. 다른 세션들의 캐시도 로드
        try:
            for dir_name in os.listdir(self.configfuzz_path):
                if dir_name.startswith("output_") and dir_name != self.output_dir_name:
                    cache_file = os.path.join(self.configfuzz_path, dir_name, "macro_cache.json")
                    if os.path.exists(cache_file):
                        with open(cache_file, 'r') as f:
                            cached = json.load(f)
                            # 기존 캐시에 없는 항목만 추가
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
                # 우선순위 매크로
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
            # 버퍼 크기 관련 매크로는 다양한 값 시도
            if 'BUFLEN' in macro or 'SIZE' in macro:
                macro_changes[macro] = random.choice([64, 128, 256, 512, 1024, 2048])
            elif 'MAX' in macro:
                macro_changes[macro] = random.choice([1, 2, 4, 8, 16, 32])
            else:
                # 일반 매크로는 0/1
                macro_changes[macro] = random.choice([0, 1])
                
        return macro_changes
    
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
        
    def analyze_stack_usage(self, test_id):
        """전체 .su 파일에서 스택 사용량 분석 (개선된 버전)"""
        high_stack_functions = []
        all_stack_functions = {}
        
        # 모든 .su 파일 찾기
        su_files = glob.glob(os.path.join(self.build_dir, "**/*.su"), recursive=True)
        
        for su_file in su_files:
            try:
                with open(su_file, 'r') as f:
                    for line in f:
                        parts = line.strip().split('\t')
                        if len(parts) >= 2:
                            func_name = parts[0]
                            try:
                                stack_size = int(parts[1])
                                
                                # 모든 함수의 스택 크기 저장
                                all_stack_functions[func_name] = stack_size
                                
                                # 임계값 이상인 함수만 high_stack에 추가
                                if stack_size >= self.stack_threshold:
                                    high_stack_functions.append({
                                        "function": func_name,
                                        "stack_size": stack_size,
                                        "file": os.path.basename(su_file)
                                    })
                            except ValueError:
                                pass
            except:
                pass
                
        # 스택 크기로 정렬
        high_stack_functions.sort(key=lambda x: x['stack_size'], reverse=True)
        
        # 스택 변화 분석
        stack_changes = self.analyze_stack_changes(all_stack_functions, test_id)
        
        return high_stack_functions[:20], all_stack_functions, stack_changes  # 상위 20개
        
    def analyze_stack_changes(self, current_stack_map, test_id):
        """기준 빌드 대비 스택 변화 분석"""
        stack_changes = {
            "new_functions": [],
            "removed_functions": [],
            "increased": [],
            "decreased": [],
            "unchanged": 0
        }
        
        # 첫 번째 성공 빌드를 기준으로 설정 (success_count가 1이 되었을 때)
        if not self.baseline_stack_map and self.success_count == 1:
            self.baseline_stack_map = current_stack_map.copy()
            self.log(f"[Test {test_id}] Set as baseline with {len(self.baseline_stack_map)} functions")
            return stack_changes
        
        # 기준이 없으면 비교하지 않음
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
                    timeout=6000,
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
        """단일 테스트 실행"""
        self.test_count += 1
        test_id = self.test_count
        
        self.log(f"\n[Test {test_id}] Starting...")
        
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
                build_time = 0.1
                error_msg = cached_result.get('error')
                high_stack_functions = cached_result.get('high_stack_functions', [])
                stack_overflow_risk = cached_result.get('stack_overflow_risk', 0)
                stack_changes = cached_result.get('stack_changes', {})
                
            else:
                # 실제 빌드 수행
                self.apply_macro_changes(macro_changes, test_id)
                success, build_time, error_msg = self.run_waf_build(test_id)
                
                if success:
                    # 스택 분석
                    high_stack_functions, all_stack_map, stack_changes = self.analyze_stack_usage(test_id)
                    stack_overflow_risk = len(high_stack_functions)
                    
                    # 스택 분석 결과 저장
                    stack_file = os.path.join(self.output_dir, "stack_analysis", f"test_{test_id:06d}_stack.json")
                    with open(stack_file, 'w') as f:
                        json.dump({
                            "test_id": test_id,
                            "high_stack_count": len(high_stack_functions),
                            "high_stack_functions": high_stack_functions[:10],
                            "stack_changes": stack_changes,
                            "total_functions_analyzed": len(all_stack_map)
                        }, f, indent=2)
                else:
                    high_stack_functions = []
                    stack_overflow_risk = 0
                    stack_changes = {}
                
                # 캐시에 저장
                self.macro_cache[macro_hash] = {
                    'build_result': success,
                    'build_time': build_time,
                    'error': error_msg,
                    'high_stack_functions': high_stack_functions[:10],
                    'stack_overflow_risk': stack_overflow_risk,
                    'stack_changes': stack_changes
                }
        else:
            # 캐시 없이 빌드
            self.apply_macro_changes(macro_changes, test_id)
            success, build_time, error_msg = self.run_waf_build(test_id)
            
            if success:
                high_stack_functions, all_stack_map, stack_changes = self.analyze_stack_usage(test_id)
                stack_overflow_risk = len(high_stack_functions)
            else:
                high_stack_functions = []
                stack_overflow_risk = 0
                stack_changes = {}
        
        # 설정 저장
        config_file = os.path.join(self.output_dir, "configs", f"test_{test_id:06d}_macros.json")
        with open(config_file, 'w') as f:
            json.dump({
                "test_id": test_id,
                "timestamp": datetime.now().isoformat(),
                "macro_changes": macro_changes
            }, f, indent=2)
        
        # 결과 분석
        result = {
            "test_id": test_id,
            "timestamp": datetime.now().isoformat(),
            "macro_changes": macro_changes,
            "build_success": success,
            "build_time": build_time,
            "build_result": success,
        }
        
        if success:
            self.success_count += 1
            self.log(f"[Test {test_id}] ✅ BUILD SUCCESS in {build_time:.1f}s")
            
            # 스택 분석 결과 추가
            result["high_stack_functions"] = high_stack_functions[:10]
            result["stack_overflow_risk"] = stack_overflow_risk
            result["stack_changes_summary"] = {
                "new_functions": len(stack_changes.get("new_functions", [])),
                "removed_functions": len(stack_changes.get("removed_functions", [])),
                "increased_stack": len(stack_changes.get("increased", [])),
                "decreased_stack": len(stack_changes.get("decreased", [])),
                "unchanged": stack_changes.get("unchanged", 0)
            }
            
            # 중요한 스택 변화 로깅
            if stack_changes.get("increased"):
                self.log(f"[Test {test_id}] ⚠️  Stack increased in {len(stack_changes['increased'])} functions")
                for func in stack_changes['increased'][:3]:  # 상위 3개만
                    self.log(f"  - {func['function'][:60]}: {func['baseline']} → {func['current']} (+{func['diff']})")
                    
            if len(high_stack_functions) > 1:  # ppp_logit 외에 다른 함수가 있으면
                self.log(f"[Test {test_id}] 📊 Found {len(high_stack_functions)} high stack functions")
                for i, func in enumerate(high_stack_functions[:3]):
                    self.log(f"  {i+1}. {func['stack_size']} bytes: {func['function'][:50]}...")
                    
        else:
            self.fail_count += 1
            self.log(f"[Test {test_id}] ❌ BUILD FAILED in {build_time:.1f}s")
            if error_msg:
                result["error"] = error_msg
                self.log(f"[Test {test_id}] Error: {error_msg[:100]}...")
                
        # 결과 저장 (ConfigFuzz 형식)
        meta_file = os.path.join(self.output_dir, f"result_ardupilot_{test_id-1}.json_meta_results.json")
        with open(meta_file, 'w') as f:
            json.dump({
                "build_result": success,
                "start_time": time.time() - build_time,
                "end_time": time.time(),
                "total_time": build_time,
                "unique_stack_smash_count": stack_overflow_risk if success else 0
            }, f)
            
        config_results_file = os.path.join(self.output_dir, f"result_ardupilot_{test_id-1}.json_config_results.json")
        with open(config_results_file, 'w') as f:
            json.dump([result], f, indent=2)
            
        result_file = os.path.join(self.output_dir, "results", f"test_{test_id:06d}_result.json")
        with open(result_file, 'w') as f:
            json.dump(result, f, indent=2)
            
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
        self.log(f"  Stack threshold: {self.stack_threshold} bytes")
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
        
        # 스택 변화 통계 수집
        stack_change_stats = {
            "total_changes": 0,
            "max_increase": 0,
            "max_decrease": 0,
            "functions_with_changes": set()
        }
        
        # stack_analysis 디렉토리의 모든 파일 분석
        stack_files = glob.glob(os.path.join(self.output_dir, "stack_analysis", "*.json"))
        for stack_file in stack_files:
            try:
                with open(stack_file, 'r') as f:
                    data = json.load(f)
                    changes = data.get("stack_changes", {})
                    
                    for func in changes.get("increased", []):
                        stack_change_stats["total_changes"] += 1
                        stack_change_stats["max_increase"] = max(stack_change_stats["max_increase"], func["diff"])
                        stack_change_stats["functions_with_changes"].add(func["function"])
                        
                    for func in changes.get("decreased", []):
                        stack_change_stats["total_changes"] += 1
                        stack_change_stats["max_decrease"] = max(stack_change_stats["max_decrease"], -func["diff"])
                        stack_change_stats["functions_with_changes"].add(func["function"])
            except:
                pass
        
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
                "success_rate": self.success_count / self.test_count * 100 if self.test_count > 0 else 0
            },
            "performance": {
                "tests_per_hour": self.test_count / (elapsed / 3600) if elapsed > 0 else 0,
                "average_build_time": elapsed / self.test_count if self.test_count > 0 else 0,
                "cache_hits": self.cache_hits if self.use_cache else 0,
                "cache_hit_rate": self.cache_hits / self.test_count * 100 if self.use_cache and self.test_count > 0 else 0
            },
            "stack_analysis": {
                "threshold": self.stack_threshold,
                "total_stack_changes": stack_change_stats["total_changes"],
                "max_stack_increase": stack_change_stats["max_increase"],
                "max_stack_decrease": stack_change_stats["max_decrease"],
                "functions_with_changes": len(stack_change_stats["functions_with_changes"])
            }
        }
        
        # JSON 리포트
        report_path = os.path.join(self.output_dir, "final_report.json")
        with open(report_path, 'w') as f:
            json.dump(report, f, indent=2)
            
        # 텍스트 리포트
        txt_report_path = os.path.join(self.output_dir, "final_report.txt")
        with open(txt_report_path, 'w') as f:
            f.write("ConfigFuzz + Waf Integration v2 Report\n")
            f.write("=====================================\n\n")
            f.write(f"Duration: {report['session_info']['duration_formatted']}\n")
            f.write(f"Total tests: {self.test_count}\n")
            f.write(f"Success rate: {report['results']['success_rate']:.1f}%\n")
            f.write(f"Average rate: {report['performance']['tests_per_hour']:.1f} tests/hour\n")
            f.write(f"\nSuccessful builds: {self.success_count}\n")
            f.write(f"Failed builds: {self.fail_count}\n")
            if self.use_cache:
                f.write(f"Cache hits: {self.cache_hits} ({report['performance']['cache_hit_rate']:.1f}%)\n")
            f.write(f"\nStack Analysis:\n")
            f.write(f"  Threshold: {self.stack_threshold} bytes\n")
            f.write(f"  Total stack changes: {stack_change_stats['total_changes']}\n")
            f.write(f"  Max increase: {stack_change_stats['max_increase']} bytes\n")
            f.write(f"  Max decrease: {stack_change_stats['max_decrease']} bytes\n")
            f.write(f"  Functions affected: {len(stack_change_stats['functions_with_changes'])}\n")
            
        self.log(f"\nFinal report saved to: {self.output_dir_name}/final_report.json")
        
    def run(self):
        """메인 실행 루프"""
        if not self.resumed_session:
            self.log("Starting ConfigFuzz + Waf fuzzing v2...")
        else:
            self.log("Resuming ConfigFuzz + Waf fuzzing v2...")
        
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
            if self.use_cache:
                self.log(f"Cache hits: {self.cache_hits}")
            self.save_final_report()
            self.main_log.close()


def main():
    parser = argparse.ArgumentParser(
        description="ConfigFuzz + Waf Integration v2 with Resume Support",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  # Start new session
  python3 configfuzz_waf_runner_v2.py --hours 6
  
  # Resume previous session
  python3 configfuzz_waf_runner_v2.py --resume output_waf_v2_20250812_135802 --hours 3
  
  # Resume with just directory name
  python3 configfuzz_waf_runner_v2.py --resume output_waf_v2_20250812_135802
  
  # Other options
  python3 configfuzz_waf_runner_v2.py --minutes 30      # Run for 30 minutes
  python3 configfuzz_waf_runner_v2.py --no-cache        # Disable cache
  python3 configfuzz_waf_runner_v2.py --threshold 256   # Use 256 byte threshold
        """
    )
    
    # Resume argument
    parser.add_argument(
        "--resume",
        type=str,
        help="Resume from previous session directory"
    )
    
    # Time arguments (mutually exclusive)
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
    
    # Other arguments
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
    
    # 시간 계산
    if args.hours:
        timeout = int(args.hours * 3600)
    elif args.minutes:
        timeout = int(args.minutes * 60)
    elif args.seconds:
        timeout = args.seconds
    else:
        # 기본값: 1시간
        timeout = 3600
        
    # 캐시 설정
    use_cache = not args.no_cache
    
    # 실행
    fuzzer = ConfigFuzzWafRunnerV2(
        timeout_seconds=timeout, 
        use_cache=use_cache,
        stack_threshold=args.threshold,
        resume_from=args.resume
    )
    fuzzer.run()


if __name__ == "__main__":
    main()
