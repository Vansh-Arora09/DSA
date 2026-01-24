class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        sort(nums.begin(),nums.end());
        int maxi=0;
        while(l<r){
            int sum = nums[l] + nums[r];
            maxi = max(sum,maxi);
            l++;
            r--;
        }
        return maxi;
    }
};