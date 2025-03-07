
import os
import re
from typing import List, Dict, Set, Tuple, Optional
import logging

logger = logging.getLogger(__name__)


class ConditionExtractor:
 

    def __init__(self, base_dir: str, file_extensions: List[str] = None):
        """
        초기화 함수

        Args:
            base_dir (str): 소스 코드 디렉토리 경로
            file_extensions (List[str], optional): 분석할 파일 확장자 목록. 기본값은 ['.c', '.cpp', '.h', '.hpp']
        """
        self.base_dir = os.path.abspath(base_dir)
        self.file_extensions = file_extensions or ['.c', '.cpp', '.h', '.hpp']
        # 조건식 패턴: #if, #ifdef, #ifndef, #elif 등을 포함
        self.condition_pattern = re.compile(r'^\s*#\s*(if|ifdef|ifndef|elif)\s+(.*?)(?://.*)?$', re.MULTILINE)
        # 단순 매크로 패턴: 단순히 매크로 이름만 있는 경우 (예: #ifdef DEBUG)
        self.simple_macro_pattern = re.compile(r'^\s*[A-Za-z_][A-Za-z0-9_]*\s*$')
        # 조건식 결과 저장
        self.conditions: Dict[str, Set[str]] = {}  # 파일별 조건식 목록
        self.all_conditions: Set[str] = set()  # 모든 조건식 목록

    def extract_conditions_from_file(self, file_path: str) -> Set[str]:

        try:
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()
            
            conditions = set()
            for match in self.condition_pattern.finditer(content):
                directive, condition = match.groups()
                
                condition = condition.strip()
                
                # #ifdef, #ifndef의 경우 조건식으로 변환
                if directive == 'ifdef':
                    if self.simple_macro_pattern.match(condition):
                        continue
                    condition = f"defined({condition})"
                elif directive == 'ifndef':
                    if self.simple_macro_pattern.match(condition):
                        continue
                    condition = f"!defined({condition})"
                
                if self.simple_macro_pattern.match(condition):
                    continue

                if condition:
                    conditions.add(condition)
            
            return conditions
        
        except Exception as e:
            logger.error(f"Error extracting conditions from {file_path}: {e}")
            return set()

    def extract_all_conditions(self) -> Dict[str, Set[str]]:

        self.conditions = {}
        self.all_conditions = set()
        
        for root, _, files in os.walk(self.base_dir):
            for file in files:
                if any(file.endswith(ext) for ext in self.file_extensions):
                    file_path = os.path.join(root, file)
                    rel_path = os.path.relpath(file_path, self.base_dir)
                    
                    file_conditions = self.extract_conditions_from_file(file_path)
                    if file_conditions:
                        self.conditions[rel_path] = file_conditions
                        self.all_conditions.update(file_conditions)
        
        return self.conditions

    def get_all_unique_conditions(self) -> Set[str]:

        return self.all_conditions

    def get_conditions_by_file(self) -> Dict[str, Set[str]]:

        return self.conditions 