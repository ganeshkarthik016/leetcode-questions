class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int n = s.size();
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(i+1<n&&s[i+1]==')'){
                    i++;
                }
                else{
                     ans++;
                }
                if (!st.empty()){
                    st.pop();
                }else{
                    ans++;
                }
            }
            }
        if(!st.empty()){
                ans += 2*st.size();
        }
        return ans;
    }
};