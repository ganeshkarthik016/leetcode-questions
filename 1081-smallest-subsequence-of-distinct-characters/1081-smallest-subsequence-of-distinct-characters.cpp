class Solution {
public:
    string smallestSubsequence(string s) {
                unordered_map<char, int> freq;
        unordered_map<char, int> stackFreq;

        for(char c : s)
            freq[c]++;

        stack<char> st;

        for(char c : s) {
            freq[c]--;
            if(stackFreq[c] > 0)
                continue;

            while(!st.empty() &&
                  st.top() > c &&
                  freq[st.top()] > 0) {

                stackFreq[st.top()]--;
                st.pop();
            }

            st.push(c);
            stackFreq[c]++;
        }

        string ans;

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};