class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mp1 = {}
        mp2 = {}

        if len(s) != len(t):
            return False

        for i in range(len(s)):
            if s[i] in mp1 and mp1[s[i]] != t[i]:
                return False

            if t[i] in mp2 and mp2[t[i]] != s[i]:
                return False

            mp1[s[i]] = t[i]
            mp2[t[i]] = s[i]

        return True