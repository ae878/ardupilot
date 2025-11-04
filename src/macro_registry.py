from typing import FrozenSet, Iterable
_known: FrozenSet[str] = frozenset()

def set_known_macros(names: Iterable[str]) -> None:
    global _known
    _known = frozenset(names)

def known_macros() -> FrozenSet[str]:
    return _known
