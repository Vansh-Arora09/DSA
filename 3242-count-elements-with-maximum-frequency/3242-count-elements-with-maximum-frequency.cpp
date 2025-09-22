class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int freq=0;
        for(auto it:mpp){
            if(it.second>freq) freq=it.second;
        }
        int sum=0;
        for(auto it:mpp){
            if(it.second==freq) sum+=it.second;
        }
        return sum;
    }
};