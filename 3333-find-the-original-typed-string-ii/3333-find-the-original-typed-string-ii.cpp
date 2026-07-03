class Solution {
public:
    const int MOD = 1e9 + 7;

    int possibleStringCount(string word, int k) {
        vector<int> extra;

        int groups = 1, cnt = 1;

        for (int i = 1; i < word.size(); i++) {
            if (word[i] == word[i - 1]) {
                cnt++;
            } else {
                if (cnt > 1) extra.push_back(cnt - 1);
                cnt = 1;
                groups++;
            }
        }
        if (cnt > 1) extra.push_back(cnt - 1);

        // Minimum possible length
        k -= groups;

        long long total = 1;
        for (int x : extra)
            total = total * (x + 1) % MOD;

        if (k <= 0) return total;

        vector<int> dp(k, 0);
        dp[0] = 1;

        for (int x : extra) {
            vector<int> ndp(k, 0);
            vector<long long> pref(k + 1, 0);

            for (int i = 0; i < k; i++)
                pref[i + 1] = (pref[i] + dp[i]) % MOD;

            for (int s = 0; s < k; s++) {
                int L = max(0, s - x);
                int R = s;

                ndp[s] = (pref[R + 1] - pref[L] + MOD) % MOD;
            }

            dp = ndp;
        }

        long long bad = 0;
        for (int i = 0; i < k; i++)
            bad = (bad + dp[i]) % MOD;

        return (total - bad + MOD) % MOD;
    }
};