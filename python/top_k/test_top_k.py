import pytest

def solve(pairs: list[tuple[str, int]], k: int) -> list[tuple[str, int]]:
    """
    SPEC:
    - Entradas: una lista de pares [("a", 10), ("b", 2), ("c", 5), ("d", 20)]
    - Salidas: una lista de pares  con los k elementos con mayor valor, ordenados descendente.
    - Reglas/empates: si hay empate, se ordenan alfabéticamente por la clave.
    - Edge cases: si k es mayor que la cantidad de elementos, se devuelven todos los elementos.
    - Complejidad: O(n log n) o mejor.

    Pseudo:
    1. Ordenar la lista de pares por el segundo elemento.
    2. Si hay empate, ordenar alfabeticamente por el primer elemento.
    3. Tomar los primeros k elementos.
    4. Devolverlos como una lista de tuplas.
    """
    # Ordenar por valor (segundo elemento) descendente y luego por clave (primer elemento) ascendente y retornar los primeros k elementos
    return sorted(pairs, key=lambda x: (-x[1], x[0]))[:k]
    

@pytest.mark.parametrize("input, expected", [
    # Cada input es una tupla con los argumentos para solve()
    (([("a", 10), ("b", 5), ("c", 7)], 2), [("a", 10), ("c", 7)]),
    (([], 0), []),
    (([("x", 5), ("y", 5), ("a", 9)], 2), [("a", 9), ("x", 5)]),
])
def test_solve(input, expected):
    assert solve(*input) == expected
