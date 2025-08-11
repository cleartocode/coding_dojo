import pytest

def solve(...):
    """
    SPEC:
    - Entradas:
    - Salidas:
    - Reglas/empates:
    - Edge cases:
    """
    # TODO: implementar
    return ...

@pytest.mark.parametrize("inp, expected", [
    # Cada inp es una tupla con los argumentos para solve()
    ((...), ...),
    ((...), ...),
    ((...), ...),
])
def test_solve(inp, expected):
    assert solve(*inp) == expected
