class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
           int rem = target - nums[i];
           if(m.find(rem)!=m.end()){
            ans = {m[rem],i};
           }
           else{
            m[nums[i]] = i;
           }
        }
        return ans;
    }
};