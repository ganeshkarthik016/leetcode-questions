class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        mp = {}
        n = len(nums)
        for i in range(n):
            rem = target-nums[i]
            if rem in mp:
                return [mp[rem],i]
            else:
                mp[nums[i]] = i
        return -1