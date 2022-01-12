class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [num for num in nums]
        for i in range(2, len(nums)):
            dp[i] += max(dp[:i-1])
        return max(dp)
