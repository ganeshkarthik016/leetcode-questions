class Solution {
public:

    unordered_set<string> st;

    void dfs(string &s, int idx, int lrem, int rrem,
             int open, int close, string path) {

        if(idx == s.size()) {
            if(lrem == 0 && rrem == 0 && open == close)
                st.insert(path);
            return;
        }

        char c = s[idx];

        if(c == '(') {

            // Remove this '('
            if(lrem > 0)
                dfs(s, idx + 1, lrem - 1, rrem,
                    open, close, path);

            // Keep this '('
            dfs(s, idx + 1, lrem, rrem,
                open + 1, close, path + '(');
        }

        else if(c == ')') {

            // Remove this ')'
            if(rrem > 0)
                dfs(s, idx + 1, lrem, rrem - 1,
                    open, close, path);

            // Keep this ')' only if it has a matching '('
            if(close < open)
                dfs(s, idx + 1, lrem, rrem,
                    open, close + 1, path + ')');
        }

        else {
            dfs(s, idx + 1, lrem, rrem,
                open, close, path + c);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int lrem = 0, rrem = 0;

        for(char c : s) {

            if(c == '(') {
                lrem++;
            }
            else if(c == ')') {

                if(lrem == 0)
                    rrem++;
                else
                    lrem--;
            }
        }

        dfs(s, 0, lrem, rrem, 0, 0, "");

        return vector<string>(st.begin(), st.end());
    }
};