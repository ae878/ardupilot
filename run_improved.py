#!/usr/bin/env python3
"""
Improved ConfigFuzz runner for ArduPilot
Fixes common issues:
- Build path mismatch
- Initial analysis timeout
- Proper error handling
"""

import sys
import os
import time
import json
import argparse
import signal
from typing import List, Dict

# Add conffuzz to path
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from src.adapter.ardupilot.ardupilot import ArdupilotAdapter
from src.config.config import ConfigFactory
from src.config.conditional_config import Condition
from src.fuzzer import Fuzzer
from src.utils.logging import get_logger

logger = get_logger(__name__)


class TimeoutError(Exception):
    pass


def timeout_handler(signum, frame):
    raise TimeoutError("Operation timed out")


class ImprovedArdupilotAdapter(ArdupilotAdapter):
    """Improved adapter with better error handling"""
    
    def build(self, config=None):
        """Skip build if no build commands"""
        if not self.build_commands:
            logger.info("[+] No build commands, skipping build phase")
            return True
        return super().build(config)
    
    def initial_analyze(self, output_dir="initial_analyze"):
        """Initial analyze with timeout protection"""
        # Check if pickle already exists
        pickle_path = os.path.join(output_dir, "phase2.pkl")
        if os.path.exists(pickle_path):
            logger.info(f"[+] Using existing pickle file: {pickle_path}")
            # Load from pickle instead of re-parsing
            from src.ir2dot.gccir2dot import Parser
            self.parser = Parser(self.base, "", output_dir, is_save_pkl=True, is_load_pkl=True, is_only_test=False)
            self.parser.load_from_pkl("phase2.pkl")
            return
        
        # Otherwise run normal initial analyze with timeout
        logger.info("[+] Running initial analysis (this may take a while)...")
        super().initial_analyze(output_dir)


def fix_build_paths():
    """Fix build path inconsistencies"""
    logger.info("[*] Fixing build paths...")
    
    # Fix build_commands.json
    build_cmd_path = "src/adapter/ardupilot/build_commands.json"
    if os.path.exists(build_cmd_path):
        with open(build_cmd_path, 'r') as f:
            build_commands = json.load(f)
        
        # Fix paths
        for cmd in build_commands:
            if 'directory' in cmd:
                cmd['directory'] = cmd['directory'].replace('R9Pilot', 'AIRLink')
        
        with open(build_cmd_path, 'w') as f:
            json.dump(build_commands, f, indent=2)
        logger.info("[+] Fixed build_commands.json")


def run_fuzzing(args):
    """Main fuzzing logic"""
    
    # Fix paths first
    fix_build_paths()
    
    # Load configurations
    logger.info("[*] Loading configurations...")
    
    macros_path = "src/adapter/ardupilot/macros.json"
    condition_path = "src/adapter/ardupilot/condition_analysis_result.json"
    thread_functions_path = "src/adapter/ardupilot/thread_functions.json"
    
    # Create config
    condition = Condition(condition_path) if args.use_sat else None
    config = ConfigFactory(macros_path, condition=condition)
    
    # Load build commands
    build_commands = []
    if not args.skip_build:
        with open("src/adapter/ardupilot/build_commands.json", 'r') as f:
            build_commands = json.load(f)
            # Limit build commands for testing
            if args.quick_test:
                build_commands = build_commands[:10]
    
    # Create adapter
    adapter = ImprovedArdupilotAdapter(
        "/home/ubuntu/lab/ardupilot",
        build_commands,
        thread_functions_file_path=thread_functions_path,
        verbose=True,
        build_base="/home/ubuntu/lab/ardupilot/build/AIRLink"  # Fixed path
    )
    
    # Create fuzzer
    fuzzer = Fuzzer(
        "/home/ubuntu/lab/ardupilot",
        adapter,
        seed_macro_file=macros_path,
        config=config,
        verbose=True
    )
    
    # Load target functions
    with open(thread_functions_path, 'r') as f:
        all_threads = json.load(f)
    
    # Select target functions
    if args.threads > 0:
        target_functions = [t['thread'] for t in all_threads[:args.threads]]
    else:
        target_functions = [t['thread'] for t in all_threads]
    
    logger.info(f"[*] Target functions: {len(target_functions)}")
    
    # Initial analysis
    if not args.skip_initial and args.use_related:
        logger.info("[*] Running initial analysis...")
        try:
            # Set timeout for initial analysis
            signal.signal(signal.SIGALRM, timeout_handler)
            signal.alarm(args.initial_timeout)
            
            fuzzer.initial_analyze(target_functions, "initial_analyze_ardupilot")
            
            signal.alarm(0)  # Cancel timeout
        except TimeoutError:
            logger.warning("[-] Initial analysis timed out, continuing anyway...")
        except Exception as e:
            logger.error(f"[-] Initial analysis failed: {e}")
            if not args.continue_on_error:
                raise
    
    # Main fuzzing loop
    logger.info("[*] Starting fuzzing loop...")
    start_time = time.time()
    
    methods = []
    if args.use_related:
        methods.append("related")
    if args.use_sat:
        methods.append("sat-validate")
    
    while True:
        if args.timeout > 0 and (time.time() - start_time) > args.timeout:
            logger.info("[*] Timeout reached, stopping...")
            break
        
        try:
            # Fuzz
            fuzzer.fuzz(methods=methods, is_dry_run=args.dry_run)
            
            if args.dry_run:
                logger.info("[*] Dry run completed")
                break
            
            # Mutate
            fuzzer.mutate(target_functions, methods=methods)
            
            # Progress report
            if fuzzer.recent_step and fuzzer.steps_count % 10 == 0:
                logger.info(f"\n[Progress Report - Step {fuzzer.steps_count}]")
                logger.info(f"  Build success rate: {fuzzer.recent_step.build_result}")
                logger.info(f"  Unique stack overflows: {fuzzer.unique_stack_smash_count}")
                
                # Check for overflows
                for func_result in fuzzer.recent_step.function_results:
                    if func_result['biggest_stack'] > func_result['source_size']:
                        logger.warning(
                            f"  OVERFLOW: {func_result['name']} - "
                            f"Used: {func_result['biggest_stack']}, "
                            f"Allocated: {func_result['source_size']}"
                        )
        
        except KeyboardInterrupt:
            logger.info("\n[*] Interrupted by user")
            break
        except Exception as e:
            logger.error(f"[-] Error in fuzzing loop: {e}")
            if not args.continue_on_error:
                raise
    
    # Final report
    logger.info("\n" + "="*60)
    logger.info("FINAL REPORT")
    logger.info("="*60)
    logger.info(f"Total steps: {fuzzer.steps_count}")
    logger.info(f"Total unique stack overflows: {fuzzer.unique_stack_smash_count}")
    logger.info(f"Time elapsed: {time.time() - start_time:.2f} seconds")
    
    # List output files
    logger.info("\nOutput files:")
    os.system("ls -la output/")


def main():
    parser = argparse.ArgumentParser(description='Improved ConfigFuzz runner')
    
    # Basic options
    parser.add_argument('-t', '--timeout', type=int, default=300,
                       help='Timeout in seconds (0 for no timeout)')
    parser.add_argument('--threads', type=int, default=10,
                       help='Number of thread functions to analyze (0 for all)')
    
    # Fuzzing options
    parser.add_argument('-r', '--use-related', action='store_true',
                       help='Use related macro fuzzing')
    parser.add_argument('-s', '--use-sat', action='store_true',
                       help='Use SAT solver for validation')
    parser.add_argument('-d', '--dry-run', action='store_true',
                       help='Dry run mode (no actual fuzzing)')
    
    # Performance options
    parser.add_argument('--skip-build', action='store_true',
                       help='Skip build phase')
    parser.add_argument('--skip-initial', action='store_true',
                       help='Skip initial analysis')
    parser.add_argument('--quick-test', action='store_true',
                       help='Quick test mode (limited builds)')
    
    # Error handling
    parser.add_argument('--continue-on-error', action='store_true',
                       help='Continue on errors')
    parser.add_argument('--initial-timeout', type=int, default=300,
                       help='Timeout for initial analysis')
    
    args = parser.parse_args()
    
    # Show configuration
    logger.info("ConfigFuzz - Improved Runner")
    logger.info(f"Configuration:")
    logger.info(f"  Timeout: {args.timeout}s")
    logger.info(f"  Threads: {args.threads}")
    logger.info(f"  Use related: {args.use_related}")
    logger.info(f"  Use SAT: {args.use_sat}")
    logger.info(f"  Skip build: {args.skip_build}")
    logger.info(f"  Skip initial: {args.skip_initial}")
    
    # Run fuzzing
    run_fuzzing(args)


if __name__ == "__main__":
    main()