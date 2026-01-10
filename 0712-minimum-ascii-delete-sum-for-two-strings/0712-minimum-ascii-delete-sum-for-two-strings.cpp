class Solution {
public:
    vector<vector<int>> dp;
    int LCS(int i, int j, int n, int m, string &s1, string &s2){
        if(i==n || j==m) return 0;
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int sum=0;
        if(s1[i]==s2[j]){
            sum = s1[i] + LCS(i+1, j+1, n,m, s1,s2);
        }
        else{
            sum = max(LCS(i+1,j,n,m,s1,s2), LCS(i,j+1,n,m,s1,s2));
        }
        return dp[i][j]=sum;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        int asciisum=0;
        dp.assign(n,vector<int>(m,INT_MAX));
        for(char c: s1){
            asciisum+=c;
        }
        for(char c : s2){
            asciisum+=c;
        }
        return asciisum - 2*LCS(0,0, n, m, s1, s2);
    }
};