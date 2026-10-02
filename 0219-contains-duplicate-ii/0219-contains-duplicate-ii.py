class Solution:
    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        mp = {}
        n = len(nums)
        for i in range(n):
            if nums[i] not in mp:
                mp[nums[i]] = i
            else:
                j = mp[nums[i]]
                sub = abs(i-j)
                if(sub<=k):
                    return True
                mp[nums[i]] = i

        return False