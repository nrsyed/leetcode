import math

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins = set(coins)
        dp = [math.inf] * (amount + 1)
        
        dp[0] = 0
        for i in range(1, amount + 1):
            if i in coins:
                dp[i] = 1
            else:
                for coin in coins:
                    diff = i - coin
                    if diff > 0 and diff < math.inf:
                        dp[i] = min(dp[i], dp[diff] + 1)
                        
        return dp[-1] if dp[-1] < math.inf else -1
