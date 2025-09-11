class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int maxlen = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ones++;
            }
            else{
                ones=0;
            }
            maxlen = max(maxlen, ones);
        }
        return maxlen;
    }
};