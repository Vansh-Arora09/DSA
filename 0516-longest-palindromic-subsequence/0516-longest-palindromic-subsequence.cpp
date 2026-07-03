class Solution {
public:
    vector<vector<int>> dp;
    int lps(string &s, int i, int j){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) dp[i][j] = lps(s, i+1, j-1)+2;
        else dp[i][j] = max(lps(s, i+1,j), lps(s, i, j-1));
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        dp.resize(s.size(), vector<int>(s.size(),-1));
        return lps(s, 0, s.size()-1);
    }
};