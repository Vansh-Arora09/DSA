class Solution {
public:
    vector<int> dp;
    int solve(vector<int>&nums, int i){
        int n = nums.size();
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        int ans = -1e9;
        int curr=0;
        for(int k=0;k<3 && (i+k)<n;k++){
            curr+=nums[i+k];
            ans = max(ans, curr - solve(nums,i+k+1));
        }
        dp[i] = ans;
        return ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n,-1);
        int res = solve(stoneValue,0);
        if(res>0) return "Alice";
        else if(res<0) return "Bob";
        else return "Tie";
    }
};