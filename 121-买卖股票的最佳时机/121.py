class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_, profit = sys.maxsize,0
        for i in prices:
            min_ = min(min_,i)
            profit = max(profit, i-min_)
        return profit