class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        long long mod = 1e9+7;

        for(int i=0;i<n;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            long long v = queries[i][3];

            if(v==1) continue;
            for(int j=l;j<=r;j+=k){
                nums[j] = (1LL * nums[j]*v) % mod;
            }
        }
        int x=0;
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
        }
        return x;
    }
};