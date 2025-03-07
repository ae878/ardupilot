

import random
import logging
from typing import Dict, Set, List, Tuple, Union, Optional, Any
from .condition_parser import (
    ASTNode, NumberNode, IdentifierNode, DefinedNode, 
    UnaryOpNode, BinaryOpNode, ConditionParser
)

logger = logging.getLogger(__name__)


class ConditionSolver:

    def __init__(self):
        self.parser = ConditionParser()
        
        # 연산자 처리 함수 매핑
        self.binary_ops = {
            '+': lambda a, b: a + b,
            '-': lambda a, b: a - b,
            '*': lambda a, b: a * b,
            '/': lambda a, b: a // b if isinstance(a, int) and isinstance(b, int) else a / b,
            '%': lambda a, b: a % b,
            '<<': lambda a, b: a << b,
            '>>': lambda a, b: a >> b,
            '<': lambda a, b: a < b,
            '<=': lambda a, b: a <= b,
            '>': lambda a, b: a > b,
            '>=': lambda a, b: a >= b,
            '==': lambda a, b: a == b,
            '!=': lambda a, b: a != b,
            '&': lambda a, b: a & b,
            '^': lambda a, b: a ^ b,
            '|': lambda a, b: a | b,
            '&&': lambda a, b: a and b,
            '||': lambda a, b: a or b
        }
        
        self.unary_ops = {
            '+': lambda a: +a,
            '-': lambda a: -a,
            '!': lambda a: not a,
            '~': lambda a: ~a
        }

    def evaluate(self, ast: ASTNode, variable_values: Dict[str, Any]) -> Any:

        if ast is None:
            return None
            
        if isinstance(ast, NumberNode):
            return ast.value
            
        elif isinstance(ast, IdentifierNode):
            if ast.name in variable_values:
                return variable_values[ast.name]
            else:
                # 기본값으로 0 반환
                return 0
                
        elif isinstance(ast, DefinedNode):
            # defined(MACRO)는 MACRO가 정의되어 있으면 1, 아니면 0
            return 1 if ast.identifier in variable_values else 0
            
        elif isinstance(ast, UnaryOpNode):
            operand = self.evaluate(ast.expr, variable_values)
            if ast.op in self.unary_ops:
                return self.unary_ops[ast.op](operand)
            else:
                raise ValueError(f"Unknown unary operator: {ast.op}")
                
        elif isinstance(ast, BinaryOpNode):
            left = self.evaluate(ast.left, variable_values)
            
            # 단락 평가 (short-circuit evaluation)
            if ast.op == '&&' and not left:
                return False
            if ast.op == '||' and left:
                return True
                
            right = self.evaluate(ast.right, variable_values)
            
            if ast.op in self.binary_ops:
                try:
                    return self.binary_ops[ast.op](left, right)
                except Exception as e:
                    logger.error(f"Error evaluating {left} {ast.op} {right}: {e}")
                    return None
            else:
                raise ValueError(f"Unknown binary operator: {ast.op}")
                
        else:
            raise ValueError(f"Unknown AST node type: {type(ast)}")

    def _generate_random_value(self, var_type: str = 'int') -> Any:

        if var_type == 'int':
            return random.randint(-100, 100)
        elif var_type == 'float':
            return random.uniform(-100.0, 100.0)
        elif var_type == 'bool':
            return random.choice([True, False])
        else:
            return random.randint(-100, 100)

    def _find_variable_types(self, ast: ASTNode) -> Dict[str, str]:

        variable_types = {}
        
        def _infer_type(node):
            if node is None:
                return
                
            if isinstance(node, IdentifierNode):
                # 기본 타입은 int로 가정
                if node.name not in variable_types:
                    variable_types[node.name] = 'int'
                    
            elif isinstance(node, DefinedNode):
                if node.identifier not in variable_types:
                    variable_types[node.identifier] = 'bool'
                    
            elif isinstance(node, UnaryOpNode):
                _infer_type(node.expr)
                
                if node.op == '!':
                    if isinstance(node.expr, IdentifierNode):
                        variable_types[node.expr.name] = 'bool'
                        
            elif isinstance(node, BinaryOpNode):
                _infer_type(node.left)
                _infer_type(node.right)
                
                if node.op in ['<', '<=', '>', '>=', '==', '!=', '&&', '||']:
                    if isinstance(node.left, IdentifierNode):
                        if node.op in ['&&', '||']:
                            variable_types[node.left.name] = 'bool'
                        elif isinstance(node.right, NumberNode) and isinstance(node.right.value, float):
                            variable_types[node.left.name] = 'float'
                            
                    if isinstance(node.right, IdentifierNode):
                        if node.op in ['&&', '||']:
                            variable_types[node.right.name] = 'bool'
                        elif isinstance(node.left, NumberNode) and isinstance(node.left.value, float):
                            variable_types[node.right.name] = 'float'
        
        _infer_type(ast)
        return variable_types

    def _generate_initial_values(self, variables: Set[str], variable_types: Dict[str, str]) -> Dict[str, Any]:

        values = {}
        for var in variables:
            var_type = variable_types.get(var, 'int')
            values[var] = self._generate_random_value(var_type)
        return values

    def _mutate_values(self, values: Dict[str, Any], variable_types: Dict[str, str]) -> Dict[str, Any]:

        new_values = values.copy()
        
        # 랜덤하게 하나의 변수 선택
        var = random.choice(list(values.keys()))
        var_type = variable_types.get(var, 'int')
        
        # 선택된 변수 값 변이
        new_values[var] = self._generate_random_value(var_type)
        
        return new_values

    def solve(self, condition: str, max_iterations: int = 100) -> Tuple[Dict[str, Any], Dict[str, Any]]:

        # 조건식 파싱
        ast = self.parser.parse(condition)
        if ast is None:
            logger.error(f"Failed to parse condition: {condition}")
            return {}, {}
            
        # 변수 추출
        variables = self.parser.extract_variables(ast)
        if not variables:
            logger.warning(f"No variables found in condition: {condition}")
            return {}, {}
            
        # 변수 타입 추론
        variable_types = self._find_variable_types(ast)
        
        # 초기 변수 값 생성
        values = self._generate_initial_values(variables, variable_types)
        

        satisfying_values = None
        non_satisfying_values = None
        
        for _ in range(max_iterations):
            # 현재 값으로 조건식 평가
            result = self.evaluate(ast, values)
            
            # 결과에 따라 값 저장
            if result:
                satisfying_values = values.copy()
            else:
                non_satisfying_values = values.copy()
                
            # 둘 다 찾았으면 종료
            if satisfying_values is not None and non_satisfying_values is not None:
                break
                
            # 값 변이
            values = self._mutate_values(values, variable_types)
            

        if satisfying_values is None:
            logger.warning(f"Could not find satisfying values for condition: {condition}")
            satisfying_values = {}
 
        if non_satisfying_values is None:
            logger.warning(f"Could not find non-satisfying values for condition: {condition}")
            non_satisfying_values = {}
            
        return satisfying_values, non_satisfying_values 