class Solution:
    def longestValidParentheses(self, s: str) -> int:
        st = []
        maxi = 0
        start = 0

        for i in range(len(s)):
            if s[i] == '(':
                st.append(i)
            else:
                if st:
                    st.pop()

                    if st:
                        maxi = max(maxi, i - st[-1])
                    else:
                        maxi = max(maxi, i - start + 1)
                else:
                    start = i + 1

        return maxi