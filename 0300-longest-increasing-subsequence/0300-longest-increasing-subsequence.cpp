class Solution {
public:
    vector<vector<int>> dp;
    int lis(vector<int> &nums, int idx, int previx){
        if(idx==nums.size()) return 0;
        if(dp[idx][previx]!=-1) return dp[idx][previx];
        int notpick = lis(nums, idx+1, previx);

        int pick = 0;
        if(previx==0 || nums[previx-1] < nums[idx]){
            pick = 1 + lis(nums,idx+1, idx+1);
        }
        return dp[idx][previx] = max(pick, notpick); 
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,vector<int>(n+1,-1));
        return lis(nums,0,0);
    }
};