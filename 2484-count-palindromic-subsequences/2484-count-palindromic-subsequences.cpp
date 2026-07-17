class Solution {
public:
    long long dp[10001][11][11][6];
    const int MOD = 1e9 + 7;

    long long dfs(int idx, int first, int second, int len, string &s) {

        if (len == 5)
            return 1;

        if (idx == s.size())
            return 0;

        if (dp[idx][first][second][len] != -1)
            return dp[idx][first][second][len];

        long long take = 0;

        int digit = s[idx] - '0';

        if (len == 0) {
            take = dfs(idx + 1, digit, second, 1, s);
        }
        else if (len == 1) {
            take = dfs(idx + 1, first, digit, 2, s);
        }
        else if (len == 2) {
            take = dfs(idx + 1, first, second, 3, s);
        }
        else if (len == 3) {
            if (digit == second)
                take = dfs(idx + 1, first, second, 4, s);
        }
        else {
            if (digit == first)
                take = dfs(idx + 1, first, second, 5, s);
        }

        long long notTake = dfs(idx + 1, first, second, len, s);

        return dp[idx][first][second][len] =
            (take + notTake) % MOD;
    }

    int countPalindromes(string s) {
        memset(dp, -1, sizeof(dp));
        return dfs(0, 10, 10, 0, s);
    }
};