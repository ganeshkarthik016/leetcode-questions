class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            string ans = "1";
            return ans;
        }
        string s = countAndSay(n-1);
        string ans = "";
        char p = s[0];
        int cnt = 0;
        for(auto c : s){
         if(c==p){
            cnt++;
         }
         else{
            ans += '0' + cnt;
            ans += p;
            cnt = 1;
            p = c;
         }
        }
        ans += '0' + cnt;
        ans += p;
        return ans;
    }
};