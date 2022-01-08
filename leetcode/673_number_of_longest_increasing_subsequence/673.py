class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        dp = [1 for _ in nums]
        dp_counts = [1 for _ in nums]
        
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        dp_counts[i] = dp_counts[j]
                    elif dp[j] + 1 == dp[i]:
                        dp_counts[i] += dp_counts[j]
                        
        max_len = max(dp)
        count = 0
        for dp_len, dp_count in zip(dp, dp_counts):
            if dp_len == max_len:
                count += dp_count
        return count
