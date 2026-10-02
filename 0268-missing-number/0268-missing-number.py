class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        n = len(nums)
        a_sum = (n)*(n+1)/2
        sum = 0
        for i in range(n):
            sum += nums[i]

        return int(a_sum-sum)