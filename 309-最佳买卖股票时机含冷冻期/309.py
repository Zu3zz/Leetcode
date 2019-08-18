class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        n = len(prices)
        dp = [[0] * 3 for _ in range(n)]
        # 0表示今天未持有 1表示今天持有 2表示今天处于冻结状态
        dp[0][0], dp[0][1], dp[0][2] = 0,-prices[0],0
        for i in range(1,n):
            dp[i][0] = max(dp[i-1][0], dp[i-1][2])
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
            dp[i][2] = dp[i-1][1] + prices[i]
        return max(dp[n-1][0], dp[n-1][2])
        