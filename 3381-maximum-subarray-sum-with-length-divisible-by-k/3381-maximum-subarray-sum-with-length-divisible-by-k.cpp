class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefsum=0;
        long long maxsum=LONG_LONG_MIN;
        vector<long long> ksum(k,LONG_LONG_MAX/2);
        ksum[k-1] = 0;
        for(int i=0;i<n;i++){
            prefsum+= nums[i];
            maxsum = max(maxsum, prefsum-ksum[i%k]);
            ksum[i%k] = min(ksum[i%k],prefsum);
        }
        return maxsum;
    }
};