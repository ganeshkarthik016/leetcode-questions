class Solution {
public:

    bool func(string &s, string &t, int i, int j, int cnt) {

        // Base Case
        if (i >= s.length() || j >= t.length()) {

            // Still characters left in s but t ended
            if (j == t.length() && i < s.length())
                return false;

            return true;
        }

        // Mismatch after already using replacement
        if (s[i] != t[j] && cnt == 1)
            return false;

        bool tmp;

        // Characters match
        if (s[i] == t[j]) {

            tmp = func(s, t, i + 1, j + 1, cnt);

        } else {

            // Either replace current character
            // OR skip current character in t
            tmp = (
                func(s, t, i + 1, j + 1, 1) ||
                func(s, t, i, j + 1, cnt)
            );
        }

        return tmp;
    }

    bool canMakeSubsequence(string s, string t) {

        // Impossible if s is larger
        if (t.length() < s.length())
            return false;

        // Small optimization for equal lengths
        if (t.length() == s.length()) {

            int cnt = 0;

            for (int i = 0; i < s.length(); i++) {

                if (s[i] != t[i])
                    cnt++;

                if (cnt > 1)
                    return false;
            }
        }

        return func(s, t, 0, 0, 0);
    }
};