class Solution {
public:
    int n, t;
    int dp[105][5005];
    int f(int i, int sum, vector<int> &nums){
        if(sum == t) return 0;
        if(i >= n || sum > t) return 1e9;
        if(dp[i][sum] != -1) return dp[i][sum];
        int nt = f(i + 1, sum, nums);
        int ans = nt;
        
        int cur = nums[i], cost = 0;
        int mt = 1e9;
        while(cur <= t){
            mt = min(mt, cost + f(i + 1, sum + cur, nums));
            cur *= 2;
            cost++;
        }
        ans = min(mt, ans);

        cur = nums[i];
        cost = 0;
        int dt = 1e9;
        while(cur > 0){
            dt = min(dt, cost + f(i + 1, sum + cur, nums));
            cur /= 2;
            cost++;
        }
        ans = min(ans, dt);
        return dp[i][sum] = ans;
    }
    int minOperations(vector<int>& nums, int sum) {
        n = nums.size();
        t = sum;
        memset(dp, -1, sizeof(dp));
        int ans = f(0, 0, nums);
        return ans == 1e9 ? -1 : ans;
    }
};