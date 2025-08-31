class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero=0;
        int window = 0;
        int strt=0;
        for(int i=0;i<nums.size();i++){
            zero+=(nums[i]==0);
            while(zero>1){
                zero-=(nums[strt]==0);
                strt++;
            }
            window = max(window,i-strt);
        }
        return window;
    }
};