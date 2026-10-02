class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int ans = 1;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int x = it;
                int cnt = 1;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};