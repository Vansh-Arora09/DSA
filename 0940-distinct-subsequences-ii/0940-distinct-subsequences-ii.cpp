class Solution {
public:
    const long long mod=1e9+7;
    int distinctSubseqII(string s) {
        long long dp=0;
        vector<long long> last(26,0);
        long long new_dp=0;
        for(char ch : s){
            long long old=dp;
            dp = (2*old+1 - last[ch-'a']+mod)%mod;
            last[ch-'a'] = (old+1)%mod;
        }
        return dp;

    }
};