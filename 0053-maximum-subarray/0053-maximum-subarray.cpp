class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int Csum = nums[0];
        int Msum = nums[0];
        for(int i=1;i<n;i++){
            Csum = max(nums[i], nums[i] + Csum);
            Msum = max(Msum,Csum);
        }
        return Msum;
    }
};