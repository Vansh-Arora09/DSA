class Solution {
public:
    int helper(int m, int n, vector<vector<vector<bool>>> &dp, vector<vector<int>>&grid){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int x=0;x<1024;x++){
                    if(!dp[i][j][x]) continue;
                    if(j+1<n){
                        int newX = x^grid[i][j+1];
                        dp[i][j+1][newX] = true;
                    }
                    if(i+1<m){
                        int newX = x^grid[i+1][j];
                        dp[i+1][j][newX] = true;
                    }
                }
            }
        }
        for(int x=0;x<1024;x++){
            if(dp[m-1][n-1][x]) return x;
        }
        return -1;
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(1024,false)));
        dp[0][0][grid[0][0]]=true;
        return helper(m,n, dp, grid);
    }
};