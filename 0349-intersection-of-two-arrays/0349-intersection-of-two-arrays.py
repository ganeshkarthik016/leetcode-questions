class Solution:
    def intersection(self, n1: list[int], n2: list[int]) -> list[int]:

        mp = {}
        for i in range(len(n1)):
            if n1[i] in mp:
                mp[n1[i]] += 1
            else:
               mp[n1[i]] = 1

        st = set()
        for i in range(len(n2)):
            if n2[i] in mp:
                st.add(n2[i])

        return list(st)