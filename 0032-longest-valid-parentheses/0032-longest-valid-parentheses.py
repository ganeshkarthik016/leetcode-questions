class Solution:
    def longestValidParentheses(self, s: str) -> int:
        st = [-1]
        maxi = 0

        for i in range(len(s)):
            if s[i] == '(':
                st.append(i)
            else:
                st.pop()

                if not st:
                    st.append(i)
                else:
                    maxi = max(maxi, i - st[-1])

        return maxi