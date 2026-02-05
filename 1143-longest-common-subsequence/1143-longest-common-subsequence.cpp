class Solution {
public:

    vector<vector<int>> dp;
    int lcs(string &s1,string &s2, int i, int j){
        if(i==s1.size() || j==s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return 1 + lcs(s1,s2,i+1,j+1);
        }
        int op1 = lcs(s1,s2,i,j+1);
        int op2 = lcs(s1,s2, i+1,j);
        return dp[i][j] = max(op1,op2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(), vector<int>(text2.size(),-1));
        return lcs(text1,text2,0,0);
    }
};