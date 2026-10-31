class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = 1e18;

        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if(d != dist[u][cnt]) continue;

            for(auto &[v, w] : adj[u]) {

                int ncnt;

                if(labels[v] == labels[u])
                    ncnt = cnt + 1;
                else
                    ncnt = 1;

                if(ncnt > k) continue;

                long long nd = d + w;

                if(nd < dist[v][ncnt]) {
                    dist[v][ncnt] = nd;
                    pq.push({nd, v, ncnt});
                }
            }
        }

        long long ans = INF;

        for(int cnt = 1; cnt <= k; cnt++) {
            ans = min(ans, dist[n - 1][cnt]);
        }

        return ans == INF ? -1 : (int)ans;
    }
};