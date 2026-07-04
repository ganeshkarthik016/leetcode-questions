class Solution {
public:
    int mod=1e9+7,dp[101][101][101];
    string a,b,t;
    int dfs(int i,int j,int k){
        if(k==t.size())return i&&j;
        if(i==a.size()&&j==b.size())return 0;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        long long ans=0;
        for(int x=i;x<a.size();x++)
            if(a[x]==t[k])
                ans=(ans+dfs(x+1,j,k+1))%mod;
        for(int x=j;x<b.size();x++)
            if(b[x]==t[k])
                ans=(ans+dfs(i,x+1,k+1))%mod;
        return dp[i][j][k]=ans;
    }
    int interleaveCharacters(string word1,string word2,string target){
        a=word1;
        b=word2;
        t=target;
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,0);
    }
};