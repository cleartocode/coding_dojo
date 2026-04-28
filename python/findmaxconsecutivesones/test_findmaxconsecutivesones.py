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
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        left: int = 0
        max_consecutive: int = 0
        
        for right in range(len(nums)):
            if nums[right] == 0:
                left = right + 1
            else:
                max_consecutive = max(max_consecutive, right - left + 1)
                
        return max_consecutive

@pytest.mark.parametrize("inputs, expected", [
    # ( (args,), expected_output )
    ([1, 1, 0, 1, 1, 1], 3 ),
    ([1, 0, 1, 1, 0, 1], 2 ),
])
def test_solution(inputs, expected):
    sol = Solution()
    # Cambia 'solve' por el nombre de la función de LeetCode
    assert sol.findMaxConsecutiveOnes(inputs) == expected