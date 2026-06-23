class Solution {
public:

    int zigZagArrays(int n, int l, int r) {
        static int mod = 1000000007;
        int m = r-l+1;

        vector<int> dp(m,1);

        for(int len=2;len<=n;len++){
            reverse(dp.begin(), dp.end());

            long long pref = 0;
            for(int i=0;i<m;i++){
                int old = dp[i];

                dp[i] = pref;
                pref = (pref+old)%mod;
            }
        }

        long long ans = 0;
        for(int x : dp){
            ans = (ans+x)%mod;
        }
        return (ans*2)%mod;
    }
};