class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorr=0;
        bool nonzero=false;
        for(int i : nums){
            xorr^=i;
            if(i!=0) nonzero=true;
        }
        if(!nonzero) return 0;
        if(xorr!=0) return n;
        return n-1;
    }
};