class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1e9 + 7;

        vector<vector<vector<long long>>> dp(zero+1, vector<vector<long long>>(one+1, vector<long long>(2,0)));

        // if we have 0 zeros then
        for(int i=0;i<=min(zero,limit);i++){
            dp[i][0][0]=1;
        }

        // if we have 0 ones then
        for(int j=0;j<=min(one,limit);j++){
            dp[0][j][1] = 1;    
        }

        //filling the dp

        for(int i=1;i<=zero;i++){
            for(int j=1;j<=one;j++){
                long long val0 = (dp[i-1][j][0] + dp[i-1][j][1]) % mod;
                if(i>limit){
                    val0 = (val0 - dp[i-limit-1][j][1] + mod) % mod;
                }
                dp[i][j][0] = val0;

                long long val1 = (dp[i][j-1][1] + dp[i][j-1][0]) % mod;
                if(j>limit){
                    val1 = (val1 - dp[i][j-limit-1][0] + mod) % mod;
                }
                dp[i][j][1] = val1;

            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};