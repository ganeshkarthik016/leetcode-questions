class Solution {
public:
    long long dfs(int i, int j, vector<vector<int>>& grid,
            vector<vector<int>>& vis) {

        int n = grid.size(), m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m ||
            vis[i][j] || grid[i][j] == 0)
            return 0;

        vis[i][j] = 1;

        long long  sum = grid[i][j];

        sum += dfs(i+1, j, grid, vis);
        sum += dfs(i-1, j, grid, vis);
        sum += dfs(i, j+1, grid, vis);
        sum += dfs(i, j-1, grid, vis);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {

        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (!vis[i][j] && grid[i][j] > 0) {

                    long long sum = dfs(i, j, grid, vis);

                    if (sum % k == 0)
                        ans++;
                }
            }
        }

        return ans;
    }
};