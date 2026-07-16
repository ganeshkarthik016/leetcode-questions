class Solution {
public:
    int beautySum(string s) {
        int cnt=0;
        for(int i=0; i<s.size(); i++){
            vector<int> hasharr(26,0);
            int maxi=0;
            for(int j=i; j<s.size(); j++){
                int freq = ++hasharr[s[j]-'a'];
                maxi=max(maxi,freq);
                int mini = INT_MAX;
                for(int k=0; k<26; k++){
                    if(hasharr[k]>0){
                        mini = min(mini,hasharr[k]);
                    }
                }
                cnt += (maxi-mini);
            }
        }
        return cnt;
    }
};