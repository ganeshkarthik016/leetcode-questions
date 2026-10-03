class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int maxi = 0;
        st.push(-1);
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(!st.empty()){
                    maxi = max(maxi,i-st.top()); 
                }
                else{
                    st.push(i);
                }
            }

        }
        return maxi;
    }
};