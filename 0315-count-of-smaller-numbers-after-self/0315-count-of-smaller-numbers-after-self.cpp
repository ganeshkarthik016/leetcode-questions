
class Solution {
public:
    vector<int> ans;
    vector<pair<int, int>> a;

    void merge(int low, int mid, int high) {
        vector<pair<int, int>> temp;
        int i = low, j = mid + 1;
        int cnt = 0;

        while (i <= mid && j <= high) {
            if (a[j].first < a[i].first) {
                temp.push_back(a[j]);
                cnt++;
                j++;
            } else {
                ans[a[i].second] += cnt;
                temp.push_back(a[i]);
                i++;
            }
        }

        while (i <= mid) {
            ans[a[i].second] += cnt;
            temp.push_back(a[i]);
            i++;
        }

        while (j <= high) {
            temp.push_back(a[j]);
            j++;
        }

        for (int k = low; k <= high; k++) {
            a[k] = temp[k - low];
        }
    }

    void divide(int low, int high) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;

        divide(low, mid);
        divide(mid + 1, high);

        merge(low, mid, high);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.assign(n, 0);
        a.clear();

        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        divide(0, n - 1);

        return ans;
    }
};
