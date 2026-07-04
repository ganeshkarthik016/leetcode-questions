class Solution {
public:
    int maxValidPairSum(vector<int>& a, int k) {
        int n=a.size();
        vector<int>sf(n+1);
        for(int i=n-1;i>=0;i--)
            sf[i]=max(a[i],sf[i+1]); 
        int ans=0;
        for(int i=0;i+k<n;i++)
            ans=max(ans,a[i]+sf[i+k]);
        return ans;
    }
};