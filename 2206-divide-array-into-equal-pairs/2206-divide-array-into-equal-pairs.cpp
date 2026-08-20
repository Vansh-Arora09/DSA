class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(auto i : nums){
            mpp[i]++;
        }

        for(auto [num,iter] : mpp){
            if(iter%2!=0) return false;
        }
        return true;
    }
};