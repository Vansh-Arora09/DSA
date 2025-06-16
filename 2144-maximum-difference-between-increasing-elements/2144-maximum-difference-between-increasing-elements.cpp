class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n  = nums.size();
        int maxdiff = -1;
        int premin = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>premin){
                maxdiff = max(maxdiff,nums[i]-premin);
            }
            else{
                premin = nums[i];
            }
        }
        return maxdiff;
    }
};