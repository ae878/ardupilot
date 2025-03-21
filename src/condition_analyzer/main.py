"""
조건식 분석 메인 모듈

이 모듈은 C/C++ 소스 코드에서 조건부 컴파일 지시문의 조건식을 추출하고 분석하는 기능을 제공합니다.
"""

import os
import sys
import json
import argparse
import logging
from typing import Dict, Set, List, Tuple, Union, Optional, Any

from .condition_extractor import ConditionExtractor
from .condition_parser import ConditionParser
from .condition_solver import ConditionSolver


def setup_logging(verbose: bool = False):

    log_level = logging.DEBUG if verbose else logging.INFO
    logging.basicConfig(
        level=log_level,
        format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
        handlers=[logging.StreamHandler()]
    )


def parse_args():

    parser = argparse.ArgumentParser(description='C/C++ 조건부 컴파일 지시문 분석 도구')
    
    parser.add_argument('--source-dir', '-s', type=str, required=True,
                        help='분석할 소스 코드 디렉토리 경로')
    
    parser.add_argument('--output', '-o', type=str, default='condition_analysis_result.json',
                        help='분석 결과를 저장할 파일 경로 (기본값: condition_analysis_result.json)')
    
    parser.add_argument('--extensions', '-e', type=str, nargs='+', 
                        default=['.c', '.cpp', '.h', '.hpp'],
                        help='분석할 파일 확장자 목록 (기본값: .c .cpp .h .hpp)')
    
    parser.add_argument('--max-iterations', '-m', type=int, default=100,
                        help='조건식 솔버의 최대 반복 횟수 (기본값: 100)')
    
    parser.add_argument('--verbose', '-v', action='store_true',
                        help='상세 로깅 활성화')
    
    return parser.parse_args()


def analyze_conditions(source_dir: str, file_extensions: List[str], max_iterations: int) -> Dict[str, Any]:

    # 조건식 추출
    extractor = ConditionExtractor(source_dir, file_extensions)
    conditions_by_file = extractor.extract_all_conditions()
    all_conditions = extractor.get_all_unique_conditions()
    
    logging.info(f"총 {len(all_conditions)}개의 고유한 조건식을 추출했습니다.")
    
    # 조건식 분석
    solver = ConditionSolver()
    condition_results = {}
    
    for i, condition in enumerate(all_conditions):
        logging.info(f"조건식 분석 중: {i+1}/{len(all_conditions)} - {condition}")
        
        try:
            satisfying_values, non_satisfying_values = solver.solve(condition, max_iterations)
            
            condition_results[condition] = {
                'satisfying_values': satisfying_values,
                'non_satisfying_values': non_satisfying_values
            }
        except Exception as e:
            logging.error(f"조건식 '{condition}' 분석 중 오류 발생: {e}")
            condition_results[condition] = {
                'error': str(e),
                'satisfying_values': {},
                'non_satisfying_values': {}
            }
    
    # 결과 구성
    result = {
        'source_directory': os.path.abspath(source_dir),
        'file_extensions': file_extensions,
        'total_unique_conditions': len(all_conditions),
        'conditions_by_file': {file: list(conditions) for file, conditions in conditions_by_file.items()},
        'condition_analysis': condition_results
    }
    
    return result


def save_result(result: Dict[str, Any], output_path: str):

    try:
        with open(output_path, 'w', encoding='utf-8') as f:
            json.dump(result, f, indent=2, ensure_ascii=False)
        logging.info(f"분석 결과를 '{output_path}'에 저장했습니다.")
    except Exception as e:
        logging.error(f"결과 저장 중 오류 발생: {e}")


def main():
    """
    메인 함수
    """
    args = parse_args()
    setup_logging(args.verbose)
    
    logging.info(f"소스 디렉토리: {args.source_dir}")
    logging.info(f"파일 확장자: {args.extensions}")
    
    result = analyze_conditions(args.source_dir, args.extensions, args.max_iterations)
    save_result(result, args.output)


if __name__ == '__main__':
    main() 