import pytest

"""
PROBLEM: 
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
COMPLEXITY:
- Time: O()
- Space: O()
"""

class Solution:
    def solve(self, *args, **kwargs):
        # Implement logic here
        pass

@pytest.mark.parametrize("inputs, expected", [
    # ( (args,), expected_output )
    ( ([],), 0 ),
    ( ([],), 0 ),
    ( ([],), 0 ),
])
def test_solution(inputs, expected):
    sol = Solution()
    # Cambia 'solve' por el nombre de la función de LeetCode
    assert sol.solve(*inputs) == expected