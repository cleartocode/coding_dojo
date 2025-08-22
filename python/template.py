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

Problem:

"""


def runner(func, *args, **kwargs):
    """
    Runner runs the function that implements the solution.
    """
    return func(*args, **kwargs)


@pytest.mark.parametrize("input, expected", [
    # The first tuple is the inputs to the function run by runner().
    # The second tuple is the expected output.
    ((...), ...),
    ((...), ...),
    ((...), ...),
])
def test_solve(input, expected):
    assert runner(...) == expected
