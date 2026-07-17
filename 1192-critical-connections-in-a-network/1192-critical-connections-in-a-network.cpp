class Solution {
public:
    void dfs(int node, int par, vector<int>& vis, vector<vector<int>>& adj,
             int tin[], int low[], int& timer, vector<vector<int>> &ans) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node]) {
            if (it == par)
                continue;
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, timer, ans);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node])
                    ans.push_back({node, it});
            } else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>> adj(n);
        for (auto it : con) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int tin[n], low[n];
        int timer = 1;
        vector<vector<int>> ans;
        vector<int> vis(n,0);
        dfs(0, -1, vis, adj, tin, low, timer, ans);
        return ans;
    }
};