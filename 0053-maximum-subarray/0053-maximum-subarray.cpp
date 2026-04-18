class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans=nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            ans = max(nums[i], nums[i]+ans);
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};