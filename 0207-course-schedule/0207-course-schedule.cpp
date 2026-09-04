class Solution {
public:
    
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        
        state[node] = 1; // visiting
        
        for (int nei : adj[node]) {
            
            if (state[nei] == 1)
                return true; // cycle found
            
            if (state[nei] == 0 && dfs(nei, adj, state))
                return true;
        }
        
        state[node] = 2; // completely processed
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        
        for (auto &p : prerequisites) {
            int a = p[0];
            int b = p[1];
            
            adj[b].push_back(a);
        }
        
        vector<int> state(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            
            if (state[i] == 0) {
                
                if (dfs(i, adj, state))
                    return false;
            }
        }
        
        return true;
    }
};