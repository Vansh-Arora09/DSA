class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        mpp[0] = 1;

        int prf_sum=0;
        int total=0;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                prf_sum+=1;
            }
            else prf_sum-=1;

            for(auto &[past_sum, count] : mpp){
                if(past_sum < prf_sum){
                    total+=count;
                }
            }
            mpp[prf_sum]++;
        }
        return total;
    }
};