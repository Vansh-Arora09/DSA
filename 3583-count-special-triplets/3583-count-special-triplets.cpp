class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9+7;
        unordered_map<int,int> numcnt(nums.size()*2);
        unordered_map<int,int> numhalfcnt(nums.size()*2);

        for(int i : nums){
            numcnt[i]++;
        }

        int ans=0;
        for(int i : nums){
            int target = i*2;
            int lcnt = numhalfcnt[target];
            numhalfcnt[i]++;
            int rcnt = numcnt[target] - numhalfcnt[target];
            ans = (ans + (lcnt*1LL*rcnt % MOD)) % MOD;
        }

        return ans;


    }
};