class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()

        if len(pattern) != len(words):
            return False

        mp1 = {}
        mp2 = {}

        for i in range(len(pattern)):
            c = pattern[i]
            w = words[i]

            if c in mp1 and mp1[c] != w:
                return False

            if w in mp2 and mp2[w] != c:
                return False

            mp1[c] = w
            mp2[w] = c

        return True