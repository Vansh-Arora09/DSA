class Solution {
public:
    vector<vector<int>> dp;
    bool ispalin(string &s, int i, int j){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = (s[i]==s[j]) && ispalin(s, i+1, j-1);

    }
    bool checkPartitioning(string s) {
        int n = s.length();
        dp.resize(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ispalin(s,i,j);
            }
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n-1;j++){
                //check whether i to j is palindrome or not
                if(dp[0][i] && dp[i+1][j] && dp[j+1][n-1]) return true;
            }
        }
        return false;
    }
};