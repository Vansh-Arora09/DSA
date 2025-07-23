class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int curr=nums[0];
        int diff=-1;
        for(int i=1;i<n;i++){
            if(nums[i]>curr){
                diff = max(diff,nums[i]-curr);
            }
            else{
                curr = nums[i];
            }
        }
        return diff;
    }
};