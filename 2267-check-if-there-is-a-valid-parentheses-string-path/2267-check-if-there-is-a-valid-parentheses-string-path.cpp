class Solution {
public:
    vector<vector<char>> g;
    vector<vector<vector<int>>> dp;

    bool dfs(int i, int j, int cost) {
        int n = g.size();
        int m = g[0].size();

        if (i >= n || j >= m)
            return false;

        if (g[i][j] == '(')
            cost++;
        else
            cost--;

        if (cost < 0)
            return false;

        if (i == n - 1 && j == m - 1)
            return cost == 0;

        if (dp[i][j][cost] != -1)
            return dp[i][j][cost];

        return dp[i][j][cost] =
            dfs(i + 1, j, cost) ||
            dfs(i, j + 1, cost);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        g = grid;

        int n = g.size();
        int m = g[0].size();


        dp.assign(n, vector<vector<int>>(m, vector<int>(n + m, -1)));

        return dfs(0, 0, 0);
    }
};