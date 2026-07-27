class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 0;
        int sec_maxi = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                sec_maxi = maxi;
                maxi = nums[i];
            }
            else if(nums[i]>=sec_maxi){
                sec_maxi = nums[i];
            }
        }
        return (maxi-1)*(sec_maxi-1);
    }
};