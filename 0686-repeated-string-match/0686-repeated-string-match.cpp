class Solution {
public:
const int BASE = 256;
const int MOD = 101; // Small prime for demonstration

bool robinKarp(string text, string pattern) {
    vector<int> ans;
    int n = text.size();
    int m = pattern.size();

    int h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * BASE) % MOD;

    int pHash = 0, tHash = 0;

    // Initial hashes
    for (int i = 0; i < m; i++) {
        pHash = (BASE * pHash + pattern[i]) % MOD;
        tHash = (BASE * tHash + text[i]) % MOD;
    }

    for (int i = 0; i <= n - m; i++) {

        if (pHash == tHash) {
            int j = 0;
            while (j < m && text[i + j] == pattern[j])
                j++;

            if (j == m)
                return true;
        }

        if (i < n - m) {
            tHash = (BASE * (tHash - text[i] * h) + text[i + m]) % MOD;

            if (tHash < 0)
                tHash += MOD;
        }
    }

    return false;
}

    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int count = 1;

        while(temp.length() < b.length()){
            temp += a;
            count++;
        }

        if(robinKarp(temp,b)){
            return count;
        }

        temp += a;

        if(robinKarp(temp,b)){
            return count + 1;
        }

        return -1;
    }
};