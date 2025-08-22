import typing as t
import pytest

"""
1. Read the problem.
    a. Identify Inputs, Outputs and Rules.
    b. Identify Test Cases, write at least 3 tests.
2. Outline the Logic.
    a. Write pseudocode.
    b. Identify time and space complexity.
    c. Write fast solution, don't overoptimize.
3. Implement the logic.
    a. Write clean code.
4. Test the solution.
    a. Run tests.
    b. Debug if needed.
"""

"""
Outline here the Problem

Problem: Rotate List to the Right

Given a list, rotate the list to the right by k places.
- If k is 0 or negative, then the list should be returned as is.
- If k is a positive number, then rotate the list to the right by k places.
- If k is greater than the length of the list, use k % len(list) to minimize the number of rotations.
"""


def rotate_list_right(l: list[t.Any], k: int) -> list[t.Any]:
    if k <= 0 or not l:
        return l
    elif k > len(l):
        k = k % len(l)
    return l[-k:] + l[:-k]



def runner(*args, **kwargs):
    """
    Runner runs the function that implements the solution.
    """
    return rotate_list_right(*args, **kwargs)


@pytest.mark.parametrize("runner, input, expected", [
    # The first tuple is the inputs to the function run by runner().
    # The second tuple is the expected output.
    (runner, ([1, 2, 3], 1), [3, 1, 2]),
    (runner, (['a', 'b', 'c', 'd'], 2), ['c', 'd', 'a', 'b']),
    (runner, ([1, 2, 3], 0), [1, 2, 3]),
    (runner, ([], 0), []),
    (runner, (['a', 'b', 'c', 'd', 'e'], -2), ['a', 'b', 'c', 'd', 'e']),
    (runner, (['a', 'b', 'c', 'd'], 9), ['d', 'a', 'b', 'c']),
])
def test_solve(runner, input, expected):
    assert runner(*input) == expected
