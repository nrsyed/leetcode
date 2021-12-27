import math

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        smallest_diff = math.inf
        sum_ = None
        
        for i in range(len(nums) - 2):
            for j in range(i+1, len(nums) - 1):
                for k in range(j+1, len(nums)):
                    _sum = nums[i] + nums[j] + nums[k]
                    diff = _sum - target
                    
                    if diff == 0:
                        return _sum
                    elif abs(diff) < abs(smallest_diff):
                        smallest_diff = diff
                        sum_ = _sum
                        
        return sum_
