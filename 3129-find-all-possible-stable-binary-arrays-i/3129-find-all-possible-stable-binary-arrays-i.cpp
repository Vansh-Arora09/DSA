class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        
        int mod = 1e9 + 7;
        
        vector<vector<vector<long long>>> dp(zero+1, vector<vector<long long>>(one+1, vector<long long>(2,0)));

        // if we have 0 number of zero then
        for(int i=1;i<=min(zero, limit); i++){
            dp[i][0][0] = 1;
        }

        // if we have 0 number of one then
        for(int j=1;j<=min(one,limit);j++){
            dp[0][j][1] = 1;
        }

        // complete the dp table

        for(int i=1;i<=zero;i++){
            for(int j=1;j<=one;j++){

                // first for dp[i][j][0] last one would be 0 ;
                long long val0 = (dp[i-1][j][0] + dp[i-1][j][1]) %mod;

                if(i>limit){
                    val0 = (val0 - dp[i-limit-1][j][1] + mod) % mod;
                }
                dp[i][j][0] = val0;

                // second for dp[i][j][1] , last would be 1;
                long long val1 = (dp[i][j-1][0] + dp[i][j-1][1]) % mod;

                if(j>limit){
                    val1 = (val1 - dp[i][j-limit-1][0] + mod) % mod;
                }

                dp[i][j][1] = val1;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};