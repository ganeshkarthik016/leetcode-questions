class Solution {
public:
    bool check(int val, vector<vector<int>>& edges, vector<bool>& online,
               long long k, int n) {

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indeg(n,0);

        for(auto &e : edges){
            int u=e[0], v=e[1], w=e[2];
            if(w < val) continue;

            if(v!=n-1 && !online[v]) continue;

            adj[u].push_back({v,w});
            indeg[v]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++)
            if(indeg[i]==0)
                q.push(i);

        vector<int> topo;

        while(!q.empty()){
            int u=q.front();
            q.pop();
            topo.push_back(u);

            for(auto &[v,w]:adj[u]){
                if(--indeg[v]==0)
                    q.push(v);
            }
        }

        const long long INF = 4e18;
        vector<long long> dp(n,INF);
        dp[0]=0;

        for(int u:topo){
            if(dp[u]==INF) continue;

            for(auto &[v,w]:adj[u]){
                dp[v]=min(dp[v],dp[u]+w);
            }
        }

        return dp[n-1]<=k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n=online.size();

        int mx=0;
        for(auto &e:edges)
            mx=max(mx,e[2]);

        int lo=0, hi=mx;
        int ans=-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(check(mid,edges,online,k,n)){
                ans=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }

        return ans;
    }
};