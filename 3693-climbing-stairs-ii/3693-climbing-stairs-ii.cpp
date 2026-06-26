class Solution {
public:
        vector<int> dp;
    int minCost(vector<int>&cost, int i){
        if(i==-1) return 0;
        if(i<-1) return 1e6;
        if(dp[i]!=-1) return dp[i];
        dp[i] = minCost(cost, i-1) + cost[i] + 1;
        dp[i] = min(dp[i], minCost(cost, i-2) + cost[i] + 4);
        dp[i] = min(dp[i], minCost(cost, i-3) + cost[i] + 9);
        return dp[i];
    }
    int climbStairs(int n, vector<int>& costs) {
        dp.assign(costs.size(), -1);
        return minCost(costs, costs.size()-1);
    }
};