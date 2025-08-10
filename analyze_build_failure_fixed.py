#!/usr/bin/env python3
"""
ConfigFuzz 빌드 실패 상세 분석 도구
빌드 과정의 모든 단계를 기록하고 실패 원인을 분석합니다.
"""

import json
import subprocess
import os
import sys
import time
from datetime import datetime

def analyze_single_build():
    """단일 빌드 과정을 상세히 분석하고 기록"""
    
    log_file = "/conffuzz/failed.log"
    
    # 로그 파일 초기화
    with open(log_file, "w") as f:
        f.write("="*80 + "\n")
        f.write(f"ConfigFuzz Build Failure Analysis - {datetime.now()}\n")
        f.write("="*80 + "\n\n")
    
    def log(message, also_print=True):
        """로그 파일에 기록하고 선택적으로 화면에도 출력"""
        with open(log_file, "a") as f:
            f.write(message + "\n")
        if also_print:
            print(message)
    
    # 1. 환경 정보
    log("1. ENVIRONMENT INFORMATION")
    log("-" * 50)
    
    # 컴파일러 버전
    result = subprocess.run(["arm-none-eabi-g++", "--version"], capture_output=True, text=True)
    log(f"Compiler: {result.stdout.splitlines()[0] if result.returncode == 0 else 'ERROR'}")
    
    # 작업 디렉토리
    log(f"Current directory: {os.getcwd()}")
    
    # 2. 매크로 상태 분석
    log("\n2. MACRO CONFIGURATION")
    log("-" * 50)
    
    try:
        with open("/conffuzz/src/adapter/ardupilot/macros.json", "r") as f:
            macros = json.load(f)
            log(f"Total macros: {len(macros)}")
            
            # 중요 매크로 확인
            important_macros = [
                "CONFIG_HAL_BOARD", "HAL_BOARD_CHIBIOS", "ARDUPILOT_BUILD",
                "HAL_USE_ADC", "HAL_USE_PWM", "HAL_WITH_DSP"
            ]
            
            log("\nImportant macros:")
            if isinstance(macros, list):
                for macro in macros:
                    if isinstance(macro, dict) and macro.get("name") in important_macros:
                        log(f"  {macro['name']} = {macro.get('value', 'undefined')}")
            
            # 변경된 매크로 찾기 (최근 config와 비교)
            import glob
            config_files = sorted(glob.glob("/conffuzz/output/*_config_results.json"))
            if config_files:
                with open(config_files[-1], "r") as f:
                    recent_config = json.load(f)
                    log(f"\nRecent changed macros ({len(recent_config)} total):")
                    for name, value in list(recent_config.items())[:10]:
                        log(f"  {name} = {value}")
    
    except Exception as e:
        log(f"Error reading macros: {e}")
    
    # 3. 빌드 명령 분석
    log("\n3. BUILD COMMAND ANALYSIS")
    log("-" * 50)
    
    try:
        with open("/conffuzz/src/adapter/ardupilot/build_commands.json", "r") as f:
            build_cmds = json.load(f)
            
            if build_cmds:
                cmd = build_cmds[0]  # 첫 번째 명령 분석
                
                log(f"Target file: {cmd['file']}")
                log(f"Working directory: {cmd['directory']}")
                
                # 경로 수정: airlink -> AIRLink
                if 'airlink' in cmd['directory']:
                    cmd['directory'] = cmd['directory'].replace('airlink', 'AIRLink')
                    log(f"Fixed directory: {cmd['directory']}")
                
                log(f"Output file: {cmd['arguments'][-1] if cmd['arguments'] else 'unknown'}")
                
                # 명령 인자 분석
                args = cmd['arguments']
                log(f"\nTotal arguments: {len(args)}")
                
                log("\nCompiler flags:")
                flag_count = 0
                for arg in args:
                    if arg.startswith('-W') and flag_count < 20:
                        log(f"  Warning: {arg}")
                        flag_count += 1
                    elif arg.startswith('-f') and flag_count < 20:
                        log(f"  Feature: {arg}")
                        flag_count += 1
                    elif arg.startswith('-D') and flag_count < 20:
                        log(f"  Define: {arg}")
                        flag_count += 1
                
                log("\nInclude paths:")
                inc_count = 0
                for arg in args:
                    if arg.startswith('-I') and inc_count < 10:
                        log(f"  {arg}")
                        inc_count += 1
                
                # 4. 실제 빌드 실행
                log("\n4. BUILD EXECUTION")
                log("-" * 50)
                
                # 작업 디렉토리로 이동
                original_dir = os.getcwd()
                try:
                    os.chdir(cmd['directory'])
                    log(f"Changed to: {os.getcwd()}")
                except FileNotFoundError:
                    log(f"ERROR: Directory not found: {cmd['directory']}")
                    # AIRLink 디렉토리로 시도
                    try:
                        alt_dir = "/home/ubuntu/lab/ardupilot/build/AIRLink"
                        os.chdir(alt_dir)
                        log(f"Using alternative directory: {alt_dir}")
                    except:
                        log("ERROR: Could not change to build directory")
                        return
                
                # 빌드 명령 실행 (전체 출력 캡처)
                log("\nExecuting build command...")
                log(f"Command: {' '.join(args[:3])} ... (총 {len(args)}개 인자)")
                
                start_time = time.time()
                result = subprocess.run(
                    args,
                    capture_output=True,
                    text=True,
                    timeout=30
                )
                build_time = time.time() - start_time
                
                log(f"\nBuild completed in {build_time:.2f} seconds")
                log(f"Return code: {result.returncode}")
                
                # 5. 결과 분석
                log("\n5. BUILD RESULT ANALYSIS")
                log("-" * 50)
                
                if result.returncode == 0:
                    log("BUILD SUCCESS!")
                    
                    # 생성된 파일 확인
                    import glob
                    su_files = glob.glob("*.su")
                    opt_files = glob.glob("*.optimized")
                    
                    log(f"\nGenerated files:")
                    log(f"  Stack usage files: {len(su_files)}")
                    log(f"  Optimized IR files: {len(opt_files)}")
                    
                    if su_files:
                        with open(su_files[0], 'r') as f:
                            log(f"  Sample .su content: {f.readline().strip()}")
                
                else:
                    log("BUILD FAILED!")
                    
                    # 표준 출력
                    if result.stdout:
                        log("\nStandard output:")
                        log("-" * 40)
                        log(result.stdout[:1000])  # 처음 1000자만
                    
                    # 표준 에러 (전체)
                    log("\nStandard error (full):")
                    log("-" * 40)
                    log(result.stderr)
                    
                    # 6. 에러 분석
                    log("\n6. ERROR ANALYSIS")
                    log("-" * 50)
                    
                    error_lines = result.stderr.split('\n')
                    
                    # 에러 타입 분류
                    error_types = {
                        "fatal error": [],
                        "error:": [],
                        "warning:": [],
                        "undefined reference": [],
                        "#error": []
                    }
                    
                    for line in error_lines:
                        for error_type in error_types:
                            if error_type in line:
                                error_types[error_type].append(line.strip())
                    
                    for error_type, errors in error_types.items():
                        if errors:
                            log(f"\n{error_type.upper()} ({len(errors)} occurrences):")
                            for err in errors[:5]:  # 각 타입별 처음 5개만
                                log(f"  {err}")
                    
                    # 근본 원인 분석
                    log("\n7. ROOT CAUSE ANALYSIS")
                    log("-" * 50)
                    
                    if "#error" in result.stderr:
                        log("→ Preprocessor #error directive hit")
                        log("  This means a required macro is not defined or has wrong value")
                    
                    if "was not declared" in result.stderr or "does not name a type" in result.stderr:
                        log("→ Missing declarations or type definitions")
                        log("  Likely caused by conditional compilation excluding necessary headers")
                    
                    if "No such file or directory" in result.stderr:
                        log("→ Missing header files")
                        log("  Check if include paths are correct or if file exists")
                    
                    if "conflicting types" in result.stderr:
                        log("→ Type definition conflicts")
                        log("  Same type defined differently based on macro conditions")
                    
                    if "undefined reference" in result.stderr:
                        log("→ Linker errors")
                        log("  Functions declared but not defined (excluded by macros)")
                    
                    if "__AP_LINE__" in result.stderr:
                        log("→ Missing __AP_LINE__ macro definition")
                        log("  Need to add -D__AP_LINE__=__LINE__ to compiler flags")
                    
                    if "single-precision constants" in result.stderr:
                        log("→ Floating point precision issue")
                        log("  Need to add -fsingle-precision-constant flag")
                
                # 원래 디렉토리로 복귀
                os.chdir(original_dir)
    
    except Exception as e:
        log(f"\nException during analysis: {type(e).__name__}: {e}")
        import traceback
        log(traceback.format_exc())
    
    # 8. 요약
    log("\n8. SUMMARY")
    log("-" * 50)
    log("This analysis shows how ConfigFuzz modifies macros and attempts to rebuild.")
    log("Most builds fail because:")
    log("  1. Incompatible macro combinations")
    log("  2. Broken conditional compilation dependencies")
    log("  3. Missing type definitions or declarations")
    log("  4. Violated assumptions in the code")
    log("\nThis is NORMAL behavior for fuzzing!")
    
    log(f"\nFull analysis saved to: {log_file}")
    print(f"\nAnalysis complete. Check {log_file} for full details.")

if __name__ == "__main__":
    analyze_single_build()