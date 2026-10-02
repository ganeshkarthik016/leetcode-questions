class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        mp = {}

        for x in nums:
            mp[x] = mp.get(x, 0) + 1

        for key, value in mp.items():
            if value > len(nums) // 2:
                return key