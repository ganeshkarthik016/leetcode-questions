
class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }

    int upper_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums, target);

        if (first == -1 || nums[first] != target)
            return {-1, -1};

        int last = upper_bound(nums, target);

        if (last == -1)
            last = nums.size() - 1;
        else
            last--;

        return {first, last};
    }
};
