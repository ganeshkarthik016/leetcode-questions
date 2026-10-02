class Solution:
    def firstUniqChar(self, s: str) -> int:
        freq = {}

        for c in s:
            freq[c] = freq.get(c, 0) + 1

        for i, c in enumerate(s):
            if freq[c] == 1:
                return i

        return -1