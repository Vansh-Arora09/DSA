class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tot = accumulate(nums.begin(), nums.end(),0);
        int leftsum=0;
        int rightsum=0;

        for(int i=0;i<nums.size();i++){
            rightsum = tot - nums[i] - leftsum;
            if(leftsum==rightsum) return i;
            leftsum+=nums[i];
        }
        return -1;
    }
};