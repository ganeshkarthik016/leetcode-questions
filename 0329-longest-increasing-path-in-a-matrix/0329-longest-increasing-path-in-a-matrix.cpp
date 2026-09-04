class Solution {
public:
    vector<vector<int>> path;
    int m, n;

    int dfs(int i, int j, vector<vector<int>>& mat) {
        // Already calculated
        if (path[i][j] > 0)
            return path[i][j];

        int max_next = 0;

        // Up
        if (i > 0 && mat[i][j] < mat[i - 1][j])
            max_next = max(max_next, dfs(i - 1, j, mat));

        // Left
        if (j > 0 && mat[i][j] < mat[i][j - 1])
            max_next = max(max_next, dfs(i, j - 1, mat));

        // Down
        if (i < m - 1 && mat[i][j] < mat[i + 1][j])
            max_next = max(max_next, dfs(i + 1, j, mat));

        // Right
        if (j < n - 1 && mat[i][j] < mat[i][j + 1])
            max_next = max(max_next, dfs(i, j + 1, mat));

        return path[i][j] = 1 + max_next;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        path.assign(m, vector<int>(n, 0));

        int max_path = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                max_path = max(max_path, dfs(i, j, matrix));
            }
        }

        return max_path;
    }
};