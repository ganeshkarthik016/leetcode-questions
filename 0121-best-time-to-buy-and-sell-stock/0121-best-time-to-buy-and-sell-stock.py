class Solution:
    def maxProfit(self, p: list[int]) -> int:
        buy = p[0]
        profit = -inf
        n = len(p)
        for i in range(n):
            profit = max(profit,p[i]-buy)
            buy = min(buy,p[i])
        return profit