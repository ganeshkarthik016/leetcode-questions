class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        c = 0
        ans = []
        st = []

        for p in seq:
            if p == '(':
                group = c % 2
                st.append(group)
                ans.append(group)
                c += 1
            else:
                group = st.pop()
                ans.append(group)
                c -= 1

        return ans