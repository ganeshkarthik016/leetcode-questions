class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        ans = []
        n = len(nums)
        for i in range(n):
            if nums[i] != 0:
                ans.append(nums[i])
        for i in range(len(ans),n):
            ans.append(0)
        for i  in range(len(ans)):
            nums[i] = ans[i]
        