class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int tail_mx = 0;
        int res = 0;

        for (int i = k, j = 0; i < nums.size(); ++i, ++j)
        {
            tail_mx = max(tail_mx, nums[j]);
            res = max(res, nums[i] + tail_mx);
        }

        return res;
    }
};