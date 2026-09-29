class Solution {
public:
    int maxDepth(string s) {

        int cur = 0;
        int mx = 0;

        for(char c : s) {

            if(c == '(') {
                cur++;
                mx = max(mx, cur);
            }
            else if(c == ')') {
                cur--;
            }
        }

        return mx;
    }
};