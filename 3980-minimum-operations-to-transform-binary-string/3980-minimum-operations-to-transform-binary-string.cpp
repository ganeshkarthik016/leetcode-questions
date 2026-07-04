class Solution {
public:
    int minOperations(string s, string t) {
        if (s == t) return 0;
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) continue;
            if (s[i] == '0') {             
                s[i] = '1';
                ans++;
                continue;
            }
            // s[i] == '1', t[i] == '0'
            if (i + 1 < n && s[i + 1] == '1') { 
                s[i + 1] = '0';
                s[i] = '0';
                ans++;
                continue;
            }
            if (i - 1 >= 0 && s[i - 1] == '1') { 
                s[i] = t[i];
                ans += 1;
                ans += ('1' == t[i - 1]);
                s[i - 1] = t[i - 1];
                continue;
            }
            if (i + 1 < n && s[i + 1] == '0') { 
                s[i] = t[i];
                ans += 2;
                ans += ('1' == t[i + 1]);
                s[i + 1] = t[i + 1];
                continue;
            }
            if (i - 1 >= 0 && s[i - 1] == '0') { 
                s[i] = t[i];
                ans += 2;
                ans += ('1' == t[i - 1]);
                s[i - 1] = t[i - 1];
                continue;
            }
        }
        if (s != t) return -1;
        return ans;
    }
};