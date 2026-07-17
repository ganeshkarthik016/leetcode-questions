class Solution {
public:
    int maxScore(vector<int>& cp, int k) {

        int n = cp.size();

        int total = 0;
        for(int x : cp) total += x;

        int len = n - k;

        if(len == 0) return total;

        int cur = 0;

        for(int i = 0; i < len; i++)
            cur += cp[i];

        int mn = cur;

        for(int i = len; i < n; i++) {

            cur += cp[i];
            cur -= cp[i - len];

            mn = min(mn, cur);
        }

        return total - mn;
    }
};