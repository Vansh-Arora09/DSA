class Solution {
public:

    int LCS(string &s1, string &s2,int i, int j, vector<vector<int>>&dp){
        
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            dp[i][j] = 1+ LCS(s1,s2,i-1,j-1,dp);
        }
        else{
            dp[i][j] = max(LCS(s1,s2,i-1,j,dp) , LCS(s1,s2,i,j-1,dp));
        }
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return LCS(text1,text2,n-1,m-1,dp);
    }
};