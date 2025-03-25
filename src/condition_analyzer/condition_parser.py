import re
from typing import List, Dict, Union, Tuple, Optional, Any
import logging
from enum import Enum, auto

logger = logging.getLogger(__name__)


class TokenType(Enum):
    """토큰 유형 열거형"""

    NUMBER = auto()
    IDENTIFIER = auto()
    OPERATOR = auto()
    LPAREN = auto()
    RPAREN = auto()
    DEFINED = auto()
    EOF = auto()


class Token:

    def __init__(self, token_type: TokenType, value: str, position: int):
        self.type = token_type
        self.value = value
        self.position = position

    def __repr__(self):
        return f"Token({self.type}, '{self.value}', {self.position})"


class ASTNode:
    pass


class NumberNode(ASTNode):
    def __init__(self, value: Union[int, float]):
        self.value = value

    def __repr__(self):
        return f"Number({self.value})"


class IdentifierNode(ASTNode):
    def __init__(self, name: str):
        self.name = name

    def __repr__(self):
        return f"Identifier({self.name})"


class DefinedNode(ASTNode):
    def __init__(self, identifier: str):
        self.identifier = identifier

    def __repr__(self):
        return f"Defined({self.identifier})"


class UnaryOpNode(ASTNode):
    def __init__(self, op: str, expr: ASTNode):
        self.op = op
        self.expr = expr

    def __repr__(self):
        return f"UnaryOp({self.op}, {self.expr})"


class BinaryOpNode(ASTNode):
    def __init__(self, left: ASTNode, op: str, right: ASTNode):
        self.left = left
        self.op = op
        self.right = right

    def __repr__(self):
        return f"BinaryOp({self.left}, {self.op}, {self.right})"


class Lexer:

    def __init__(self, text: str):
        self.text = text
        self.pos = 0
        self.current_char = self.text[self.pos] if self.text else None

        # 연산자 우선순위
        self.operators = {
            "||": 1,  # 논리 OR
            "&&": 2,  # 논리 AND
            "|": 3,  # 비트 OR
            "^": 4,  # 비트 XOR
            "&": 5,  # 비트 AND
            "==": 6,
            "!=": 6,  # 동등 비교
            "<": 7,
            "<=": 7,
            ">": 7,
            ">=": 7,  # 관계 비교
            "<<": 8,
            ">>": 8,  # 비트 시프트
            "+": 9,
            "-": 9,  # 덧셈, 뺄셈
            "*": 10,
            "/": 10,
            "%": 10,  # 곱셈, 나눗셈, 나머지
        }

        # 단항 연산자
        self.unary_operators = {"+", "-", "!", "~"}

    def advance(self):

        self.pos += 1
        if self.pos >= len(self.text):
            self.current_char = None
        else:
            self.current_char = self.text[self.pos]

    def skip_whitespace(self):

        while self.current_char is not None and self.current_char.isspace():
            self.advance()

    def number(self) -> Tuple[TokenType, Union[int, float]]:

        result = ""
        is_hex = False

        # 16진수 접두사 확인
        if self.current_char == "0" and self.pos + 1 < len(self.text) and self.text[self.pos + 1].lower() == "x":
            result += self.current_char
            self.advance()
            result += self.current_char
            self.advance()
            is_hex = True

            # 16진수 숫자 파싱
            while self.current_char is not None and (
                self.current_char.isdigit() or self.current_char.lower() in "abcdef"
            ):
                result += self.current_char
                self.advance()

            return TokenType.NUMBER, int(result, 16)

        # 10진수 숫자 파싱
        while self.current_char is not None and self.current_char.isdigit():
            result += self.current_char
            self.advance()

        # 소수점 처리
        if self.current_char == ".":
            result += self.current_char
            self.advance()

            while self.current_char is not None and self.current_char.isdigit():
                result += self.current_char
                self.advance()

            return TokenType.NUMBER, float(result)

        return TokenType.NUMBER, int(result)

    def identifier(self) -> str:
        """식별자 토큰 생성"""
        result = ""
        while self.current_char is not None and (self.current_char.isalnum() or self.current_char == "_"):
            result += self.current_char
            self.advance()
        return result

    def get_next_token(self) -> Token:
        """다음 토큰 가져오기"""
        while self.current_char is not None:

            # 공백 건너뛰기
            if self.current_char.isspace():
                self.skip_whitespace()
                continue

            # 숫자 처리
            if self.current_char.isdigit():
                token_type, value = self.number()
                return Token(token_type, str(value), self.pos)

            # 식별자 처리
            if self.current_char.isalpha() or self.current_char == "_":
                start_pos = self.pos
                value = self.identifier()

                # defined 키워드 처리
                if value == "defined":
                    return Token(TokenType.DEFINED, value, start_pos)

                return Token(TokenType.IDENTIFIER, value, start_pos)

            # 괄호 처리
            if self.current_char == "(":
                token = Token(TokenType.LPAREN, "(", self.pos)
                self.advance()
                return token

            if self.current_char == ")":
                token = Token(TokenType.RPAREN, ")", self.pos)
                self.advance()
                return token

            if self.current_char in "+-*/()%<>=!&|^~":
                start_pos = self.pos
                op = self.current_char
                self.advance()

                # 두 글자 연산자 처리 (==, !=, <=, >=, &&, ||, <<, >>)
                if self.current_char is not None:
                    if (op + self.current_char) in ("==", "!=", "<=", ">=", "&&", "||", "<<", ">>"):
                        op += self.current_char
                        self.advance()

                return Token(TokenType.OPERATOR, op, start_pos)

            # 알 수 없는 문자
            raise ValueError(f"Invalid character: '{self.current_char}' at position {self.pos}")

        # 파일 끝
        return Token(TokenType.EOF, "", self.pos)


class Parser:

    def __init__(self, lexer: Lexer):
        self.lexer = lexer
        self.current_token = self.lexer.get_next_token()

        # 연산자 우선순위
        self.operators = {
            "||": 1,  # 논리 OR
            "&&": 2,  # 논리 AND
            "|": 3,  # 비트 OR
            "^": 4,  # 비트 XOR
            "&": 5,  # 비트 AND
            "==": 6,
            "!=": 6,  # 동등 비교
            "<": 7,
            "<=": 7,
            ">": 7,
            ">=": 7,  # 관계 비교
            "<<": 8,
            ">>": 8,  # 비트 시프트
            "+": 9,
            "-": 9,  # 덧셈, 뺄셈
            "*": 10,
            "/": 10,
            "%": 10,  # 곱셈, 나눗셈, 나머지
        }

        # 단항 연산자
        self.unary_operators = {"+", "-", "!", "~"}

    def eat(self, token_type: TokenType):
        """
        현재 토큰이 예상 토큰 유형과 일치하면 다음 토큰으로 이동
        """
        if self.current_token.type == token_type:
            self.current_token = self.lexer.get_next_token()
        else:
            raise SyntaxError(
                f"Expected {token_type}, got {self.current_token.type} "
                f"with value '{self.current_token.value}' at position {self.current_token.position}"
            )

    def factor(self) -> ASTNode:
        """
        factor : NUMBER | IDENTIFIER | DEFINED LPAREN IDENTIFIER RPAREN | DEFINED IDENTIFIER |
                 LPAREN expr RPAREN | unary_op factor
        """
        token = self.current_token

        if token.type == TokenType.NUMBER:
            self.eat(TokenType.NUMBER)
            return NumberNode(int(token.value) if token.value.isdigit() else float(token.value))

        elif token.type == TokenType.IDENTIFIER:
            self.eat(TokenType.IDENTIFIER)
            return IdentifierNode(token.value)

        elif token.type == TokenType.DEFINED:
            self.eat(TokenType.DEFINED)

            # defined(MACRO) 형식
            if self.current_token.type == TokenType.LPAREN:
                self.eat(TokenType.LPAREN)

                if self.current_token.type != TokenType.IDENTIFIER:
                    raise SyntaxError(f"Expected identifier after 'defined(', got {self.current_token.type}")

                identifier = self.current_token.value
                self.eat(TokenType.IDENTIFIER)
                self.eat(TokenType.RPAREN)
                return DefinedNode(identifier)

            # defined MACRO 형식
            elif self.current_token.type == TokenType.IDENTIFIER:
                identifier = self.current_token.value
                self.eat(TokenType.IDENTIFIER)
                return DefinedNode(identifier)

            else:
                raise SyntaxError(f"Expected '(' or identifier after 'defined', got {self.current_token.type}")

        elif token.type == TokenType.LPAREN:
            self.eat(TokenType.LPAREN)
            node = self.expr()
            self.eat(TokenType.RPAREN)
            return node

        elif token.type == TokenType.OPERATOR and token.value in self.unary_operators:
            op = token.value
            self.eat(TokenType.OPERATOR)
            return UnaryOpNode(op, self.factor())

        else:
            raise SyntaxError(
                f"Unexpected token: {token.type} with value '{token.value}' at position {token.position}"
            )

    def term(self) -> ASTNode:

        node = self.factor()

        while self.current_token.type == TokenType.OPERATOR and self.current_token.value in ("*", "/", "%"):
            token = self.current_token
            self.eat(TokenType.OPERATOR)
            node = BinaryOpNode(node, token.value, self.factor())

        return node

    def expr(self, min_precedence: int = 0) -> ASTNode:

        left = self.term()

        while (
            self.current_token.type == TokenType.OPERATOR
            and self.current_token.value in self.operators
            and self.operators[self.current_token.value] >= min_precedence
        ):

            op = self.current_token.value
            op_precedence = self.operators[op]
            self.eat(TokenType.OPERATOR)

            right = self.expr(op_precedence + 1)
            left = BinaryOpNode(left, op, right)

        return left

    def parse(self) -> ASTNode:
        return self.expr()


class ConditionParser:

    def __init__(self):
        pass

    def parse(self, condition: str) -> ASTNode:

        try:
            lexer = Lexer(condition)
            parser = Parser(lexer)
            return parser.parse()
        except Exception as e:
            logger.error(f"Error parsing condition '{condition}': {e}")
            return None

    def extract_variables(self, ast: ASTNode) -> set:

        variables = set()

        def _extract(node):
            if node is None:
                return

            if isinstance(node, IdentifierNode):
                variables.add(node.name)
            elif isinstance(node, DefinedNode):
                variables.add(node.identifier)
            elif isinstance(node, UnaryOpNode):
                _extract(node.expr)
            elif isinstance(node, BinaryOpNode):
                _extract(node.left)
                _extract(node.right)

        _extract(ast)
        return variables
