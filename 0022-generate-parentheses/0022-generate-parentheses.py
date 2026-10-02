class Solution:
    def dfs(self, op: int, clo: int, cur: list, n: int, ans: list):
        if op == n and clo == n:
            ans.append(''.join(cur))
            return

        if op < n:
            cur.append('(')
            self.dfs(op + 1, clo, cur, n, ans)
            cur.pop()

        if op > clo:
            cur.append(')')
            self.dfs(op, clo + 1, cur, n, ans)
            cur.pop()

    def generateParenthesis(self, n: int) -> list[str]:
        ans = []
        self.dfs(0, 0, [], n, ans)
        return ans