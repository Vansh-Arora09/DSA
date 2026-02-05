class Solution {
public:
    vector<vector<int>> dp;
    int possCoin(int idx, vector<int>&coins, int target){
        if(target==0 ){
            return 0;
        }
        
        if(idx>=coins.size()) return 1e9;
        if(dp[idx][target]!=-1) return dp[idx][target];
        int pick=1e9;
        if(coins[idx]<=target){
            pick = 1 + possCoin(idx, coins, target-coins[idx]);
        }
        int notpick = possCoin(idx+1,coins, target);

        return dp[idx][target] = min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n,vector<int>(amount+1, -1));
        int ans = possCoin(0,coins,amount);
        return ans==1e9 ? -1 : ans;
    }
};