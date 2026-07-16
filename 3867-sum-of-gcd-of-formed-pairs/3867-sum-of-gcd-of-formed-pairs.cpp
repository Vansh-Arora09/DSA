class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> mxs;
        int prf = INT_MIN;

        for(int i : nums){
            prf = max(prf, i);
            mxs.push_back(prf);
        }

        vector<int> gcd1;
        for(int i=0;i<n;i++){
            gcd1.push_back(gcd(nums[i], mxs[i]));
        }

        sort(gcd1.begin(), gcd1.end());

        long long ans=0;
        int l=0, r=n-1;
        while(l<r){
            ans+=gcd(gcd1[l], gcd1[r]);
            l++,r--;
        }
        return ans;
    }
};