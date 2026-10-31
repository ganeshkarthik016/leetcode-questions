
class Solution {
public:
    const int MOD = 1e9 + 7;

    int dfs(int i, int j, vector<vector<int>>& grid,
            int last, vector<vector<vector<int>>>& dp) {

        int n = grid.size(), m = grid[0].size();

        if (i >= n || j >= m) return 0;

        if (i == n-1 && j == m-1) return 1;

        if (dp[i][j][last] != -1)
            return dp[i][j][last];

        int ans = 0;

        if (grid[i][j] == 1) {

            if (last == 0) {
                ans = dfs(i, j+1, grid, 1, dp);
            }
            else {
                ans = dfs(i+1, j, grid, 0, dp);
            }

        }
        else {

            int down = dfs(i+1, j, grid, 0, dp);
            int right = dfs(i, j+1, grid, 1, dp);

            ans = (down + right) % MOD;
        }

        return dp[i][j][last] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(2, -1))
        );

        // Starting cell is guaranteed to be empty.
        return (dfs(1, 0, grid, 0, dp) +
                dfs(0, 1, grid, 1, dp)) % MOD;
    }
};
