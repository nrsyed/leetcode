class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        
        sum_ = nums[0] + nums[1] + nums[2]
        smallest_diff = abs(target - sum_)
        
        for i in range(len(nums) - 2):
            j = i + 1
            k = len(nums) - 1
            
            curr_val = nums[i]
            
            while j < k:
                _sum = nums[i] + nums[j] + nums[k]
                diff = abs(_sum - target)
                
                if _sum == target:
                    return _sum
                elif _sum > target:
                    k -= 1
                elif _sum < target:
                    j += 1
                    
                if diff < smallest_diff:
                    smallest_diff = diff
                    sum_ = _sum
                        
        return sum_
