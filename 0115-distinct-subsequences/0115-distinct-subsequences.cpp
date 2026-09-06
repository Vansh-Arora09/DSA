class Solution {
public:
    long long solve(int i, int j, string &s, string &t, vector<vector<long long>>&dp){
        if(j==t.length()) return 1;
        if(i==s.length()) return 0;
        if(s.length()-i < t.length()-j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        long long notTake = solve(i+1, j, s, t, dp);
        long long take=0;
        if(s[i]==t[j]) take = solve(i+1,j+1, s,t,dp);

        return dp[i][j] = take + notTake;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<long long>> dp(n, vector<long long>(m,-1));
        return solve(0,0,s,t,dp);
        
    }
};