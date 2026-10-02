class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        st = set(nums)
        ans = sorted(st)

        for i in range(len(ans)):
            nums[i] = ans[i]

        return len(ans)