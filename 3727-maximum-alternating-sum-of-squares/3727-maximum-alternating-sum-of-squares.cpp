class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
             nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        int po = (n%2==0) ? n/2 : n/2+1;
        int ne = n-po;
        long long  ans  =0;
        for(int i=0;i<ne;i++){
            ans -= nums[i];
        }
        for(int i = ne;i<n;i++){
            ans += nums[i];
        }
        return ans;
    }
};