class Solution {
public:
    vector<long long> dp;
    const int mod = 1e9+7;
    int solve(int n){
        if(n==0) return 1;
        if(n==1) return 2;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = (solve(n-1)+solve(n-2))%mod;
    }
    int countHousePlacements(int n) {
        dp.assign(n+1,-1);
        long long ways = solve(n);
        long long ans = (ways*ways)%mod;
        return ans;
    }
};