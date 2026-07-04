class Solution {
public:
    // int ans = INT_MAX;

    // void dfs(int u, vector<int>& vis,
    //          vector<vector<pair<int,int>>>& adj)
    // {
    //     vis[u] = 1;

    //     for(auto [v,w] : adj[u])
    //     {
    //         ans = min(ans, w);

    //         if(!vis[v])
    //             dfs(v, vis, adj);
    //     }
    // }

    class disjoint {
        vector<int> parent, rank, size;

    public:
        disjoint(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            size.resize(n + 1, 1);

            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }

        int find_parent(int node) {
            if (parent[node] == node)
                return node;
            return parent[node] = find_parent(parent[node]);
        }

        void union_set_rank(int u, int v) {
            int pu = find_parent(u);
            int pv = find_parent(v);

            if (pu == pv)
                return;

            if (rank[pu] < rank[pv])
                parent[pu] = pv;
            else if (rank[pv] < rank[pu])
                parent[pv] = pu;
            else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }

        void union_set_size(int u, int v) {
            int pu = find_parent(u);
            int pv = find_parent(v);

            if (pu == pv)
                return;

            if (size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
    };

    int minScore(int n, vector<vector<int>>& roads) {

        // DFS Solution
        /*
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &e : roads)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> vis(n + 1, 0);

        dfs(1, vis, adj);

        return ans;
        */

        // DSU Solution
        disjoint dsu(n);

        for (auto &e : roads)
            dsu.union_set_size(e[0], e[1]);

        int p = dsu.find_parent(1);
        int ans = INT_MAX;

        for (auto &e : roads) {
            if (dsu.find_parent(e[0]) == p)
                ans = min(ans, e[2]);
        }

        return ans;
    }
};