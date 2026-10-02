class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        ans = [0]*n
        for i in range(n):
            ans[(i+k)%n] = nums[i]
        for i in range(n):
            nums[i] = ans[i]