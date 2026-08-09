class Solution {
public:
    vector<int> dp;
    int solve(int n){
        if(n<=2) return n;
        if(dp[n]!=0) return dp[n];
        return dp[n] = solve(n-1)+solve(n-2);
    }


    int climbStairs(int n) {
        dp.assign(n+1,0);
        return solve(n);
    }
};