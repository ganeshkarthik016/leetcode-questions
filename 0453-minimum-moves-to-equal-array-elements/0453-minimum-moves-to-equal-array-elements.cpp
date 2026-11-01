class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, mini = INT_MAX;
        for (int x : nums) {
            sum += x;
            mini = min(mini, x);
        }
        return sum - nums.size() * mini;
    }
};