class Solution {
public:
    vector<int> dp;
    int solve(vector<int>&nums, int i){
        if(i>=nums.size()){
            return 0;
        }

        if(dp[i]!=-1) return dp[i];
        int curr = nums[i];
        int cur_sum = nums[i];
        int index = i+1;

        while(index<nums.size() && nums[index]==curr){
            cur_sum+=nums[i];
            index++;
        }
        while(index<nums.size() && nums[index]==curr+1){
            index++;
        }

        return dp[i] = max(cur_sum+solve(nums,index), solve(nums,i+1));

    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        dp.resize(20001,-1);
        sort(nums.begin(), nums.end());

        return solve(nums,0);
    }
};