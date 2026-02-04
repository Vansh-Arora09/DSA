class Solution {
public:
    long long maxSumTrionic(vector<int>& a) {
        int n = a.size();
         vector<vector<long long>> dp(4, vector<long long>(n, -1e18));

        long long ans = -1e18;
        for(int i = 0; i < n; i++) {
            dp[0][i] = a[i];
            if(i) {
                //start increasing 
                if(a[i] > a[i - 1]){
                    dp[1][i] = max(dp[0][i - 1] + a[i], dp[1][i - 1] + a[i]);
                }
                //start decreasing 
                if(a[i] < a[i - 1]){
                    dp[2][i] = max(dp[1][i - 1] + a[i], dp[2][i - 1] + a[i]);
                }
                //start 2nd increasing 
                if(a[i] > a[i - 1]){
                    dp[3][i] = max(dp[2][i - 1] + a[i], dp[3][i - 1] + a[i]); 
                }
            }
            ans = max(ans, dp[3][i]);
        }

        return ans;

    }
};