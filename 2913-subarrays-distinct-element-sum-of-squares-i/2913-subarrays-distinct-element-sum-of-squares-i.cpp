class Solution {
public:
    long long sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            set<int> st;

            for (int j = i; j < n; j++) {
                st.insert(nums[j]);

                long long cnt = st.size();
                ans += cnt * cnt;
            }
        }

        return ans;
    }
};