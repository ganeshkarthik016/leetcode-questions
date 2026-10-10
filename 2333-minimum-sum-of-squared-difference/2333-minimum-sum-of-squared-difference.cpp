
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<long long> a(n);

        long long mx = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            a[i] = abs((long long)nums1[i] - nums2[i]);
            mx = max(mx, a[i]);
            ans += a[i] * a[i];
        }

        if (k >= accumulate(a.begin(), a.end(), 0LL))
            return 0;

        long long l = 0, r = mx;

        while (l < r) {
            long long mid = (l + r) / 2;
            long long need = 0;

            for (long long d : a) {
                if (d > mid)
                    need += d - mid;
            }

            if (need <= k)
                r = mid;
            else
                l = mid + 1;
        }

        long long rem = k;

        for (long long &d : a) {
            if (d > l) {
                rem -= d - l;
                d = l;
            }
        }

        for (long long &d : a) {
            if (rem > 0 && d == l && l > 0) {
                d--;
                rem--;
            }
        }

        ans = 0;
        for (long long d : a)
            ans += d * d;

        return ans;
    }
};
