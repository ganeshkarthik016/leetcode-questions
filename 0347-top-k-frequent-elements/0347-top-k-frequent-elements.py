class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        mp = {}

        for x in nums:
            mp[x] = mp.get(x, 0) + 1

        arr = sorted(mp, key=mp.get, reverse=True)

        return arr[:k]