class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        ans = []
        n = len(nums)
        for i in range(n):
            if nums[i] != val:
                ans.append(nums[i])
        for i in range(len(ans)):
            nums[i] = ans[i]
        return len(ans)