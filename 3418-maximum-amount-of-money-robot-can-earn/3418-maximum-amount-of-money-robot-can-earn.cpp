class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3,-1e9)));

        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = max(coins[0][0],0);
        dp[0][0][2] = max(coins[0][0], 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;

                for(int k=0;k<3;k++){
                    int prev = -1e9;
                    if(i>0) {
                        prev = max(prev, dp[i-1][j][k]);
                    }
                    if(j>0){
                        prev = max(prev, dp[i][j-1][k]);
                    }

                    if(prev!=-1e9){
                        dp[i][j][k] = max(dp[i][j][k], prev + coins[i][j]);
                    }

                    if(k>0){
                        int prev_k = -1e9;
                        if(i>0) prev_k = max(prev_k, dp[i-1][j][k-1]);
                        if(j>0) prev_k = max(prev_k, dp[i][j-1][k-1]);

                        if(prev_k!=-1e9){
                            dp[i][j][k] = max(dp[i][j][k], prev_k);
                        }
                    }
                }
            }
        }
        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
   }
};