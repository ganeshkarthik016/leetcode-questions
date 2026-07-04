class Solution {
public:
    int ans = INT_MAX;

    void dfs(int u, vector<int>& vis,
             vector<vector<pair<int,int>>>& adj)
    {
        vis[u] = 1;

        for(auto [v,w] : adj[u])
        {
            ans = min(ans, w);

            if(!vis[v])
                dfs(v, vis, adj);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &e : roads)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> vis(n + 1, 0);

        dfs(1, vis, adj);

        return ans;
    }
};