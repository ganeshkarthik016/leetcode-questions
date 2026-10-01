class Solution:
    def isValid(self, s: str) -> bool:
        st = []

        for c in s:
            if c == '(' or c == '{' or c == '[':
                st.append(c)
            else:
                if not st:
                    return False

                top = st.pop()

                if c == ')' and top != '(':
                    return False
                if c == '}' and top != '{':
                    return False
                if c == ']' and top != '[':
                    return False

        return len(st) == 0