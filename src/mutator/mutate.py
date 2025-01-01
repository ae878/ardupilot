# 1. 할당된 스택 사이즈가 높은것을 우선순위
# 2. code size를 많이 지정하는것을 우선순위


from fuzzer import Fuzzer


def related_based_mutate(fuzzer: Fuzzer, target_function: str):
    """
    관련되어있는 매크로들만 fuzzing 진행
    """
    related_files = fuzzer.related_files_per_function[target_function]
    related_macros = fuzzer.related_macros_per_function[target_function]


def stack_based_mutate(fuzzer: Fuzzer):
    """
    이전 기록을 가지고 와 스택 사이즈가 더 큰 것을 우선순위하여 fuzzing 진행
    """

    pass


def code_based_mutate(fuzzer: Fuzzer):
    """
    코드 사이즈가 더 큰 것을 우선순위하여 fuzzing 진행
    """
    pass
