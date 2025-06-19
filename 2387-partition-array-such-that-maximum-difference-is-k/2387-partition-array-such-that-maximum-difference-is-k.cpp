class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int fir = nums[0];
        int res=1;
        for(int i=1;i<n;i++){
            if(nums[i]-fir > k){
                res++;
                fir = nums[i];
            }
        }
        return res;
    }
};