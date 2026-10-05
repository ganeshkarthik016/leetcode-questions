class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            }
            else {
                int cur = st.top();
                st.pop();

                st.top() += max(2 * cur, 1);
            }
        }

        return st.top();
    }
};