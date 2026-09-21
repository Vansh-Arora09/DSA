class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for(int num : nums) {
            vector<long long> newdp(k, 0);
            newdp[num % k]++;
            for(int r = 0; r < k; r++) {
                int newRemainder = (r * (num % k)) % k;
                newdp[newRemainder] += dp[r];
            }
            for(int r = 0; r < k; r++) {
                result[r] += newdp[r];
            }
            dp = newdp;
        }
        return result;
    }
};