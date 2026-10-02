class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        mp = {}

        for x in nums:
            mp[x] = mp.get(x, 0) + 1

        mp2 = []

        for key, value in mp.items():
            mp2.append([value, key])

        mp2.sort(reverse=True)

        ans = []

        for i in range(k):
            ans.append(mp2[i][1])

        return ans