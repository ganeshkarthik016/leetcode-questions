class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int c = 0;
        vector<int> ans;
        stack<int> st;

        for(char p : seq) {
            if(p == '(') {
                int group = c % 2;
                st.push(group);
                ans.push_back(group);
                c++;
            }
            else {
                int group = st.top();
                st.pop();
                ans.push_back(group);
                c--;
            }
        }

        return ans;
    }
};