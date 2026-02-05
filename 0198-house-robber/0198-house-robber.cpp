class Solution {
public:
    vector<int> dp;
    int rob(vector<int>&nums, int idx){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int notrob = rob(nums,idx+1);
        int robb = nums[idx] + rob(nums, idx+2);

        return dp[idx] = max(robb, notrob);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        return rob(nums,0);
    }
};