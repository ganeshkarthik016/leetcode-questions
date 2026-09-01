class Solution {
public:
    int solve(int i, int sum, vector<int>& nums, vector<vector<int>>& dp,
              vector<map<int, int>>& options) {

        if (sum == 0)
            return 0;

        if (i == nums.size() || sum < 0)
            return INT_MAX;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        int ans = INT_MAX;

        // Don't take nums[i]
        ans = solve(i + 1, sum, nums, dp, options);

        // Take nums[i] in one of its possible forms
        for (auto [value, cost] : options[i]) {

            if (value > sum)
                continue;

            int x = solve(i + 1, sum - value, nums, dp, options);

            if (x != INT_MAX)
                ans = min(ans, cost + x);
        }

        return dp[i][sum] = ans;
    }

    int minOperations(vector<int>& nums, int sum) {

        int n = nums.size();

        vector<map<int, int>> options(n);

        for (int i = 0; i < n; i++) {

            long long x = nums[i];
            int divCost = 0;

            while (x > 0) {

                long long cur = x;
                int mulCost = 0;
                while (cur <= sum) {

                    int value = (int)cur;
                    int cost = divCost + mulCost;
                    if (!options[i].count(value) || options[i][value] > cost) {

                        options[i][value] = cost;
                    }

                    cur *= 2;
                    mulCost++;
                }

                x /= 2;
                divCost++;
            }
        }

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        int ans = solve(0, sum, nums, dp, options);

        return ans == INT_MAX ? -1 : ans;
    }
};