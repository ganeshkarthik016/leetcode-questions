class Solution {
public:
    bool dfs(int i, vector<int>& v, vector<int>& dp) {
        if (i >= v.size() - 1) return true;
        if (dp[i] != -1) return dp[i];

        for (int j = 1; j <= v[i]; j++) {
            if (dfs(i + j, v, dp)) {
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(0, nums, dp);
    }
};