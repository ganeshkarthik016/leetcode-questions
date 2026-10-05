class Solution {
public:
    bool dfs(int i, int cost, string &s, vector<vector<int>> &dp) {
        int n = s.size();

        if (cost < 0)
            return false;

        if (i == n)
            return cost == 0;

        if (dp[i][cost] != -1)
            return dp[i][cost];

        bool ans = false;

        if (s[i] == '(') {
            ans = dfs(i + 1, cost + 1, s, dp);
        }
        else if (s[i] == ')') {
            ans = dfs(i + 1, cost - 1, s, dp);
        }
        else {
            ans = dfs(i + 1, cost + 1, s, dp) ||
                  dfs(i + 1, cost - 1, s, dp) ||
                  dfs(i + 1, cost, s, dp);
        }

        return dp[i][cost] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return dfs(0, 0, s, dp);
    }
};