class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(auto i : nums){
            mpp[i]++;
        }
        if(k==1){
            int track=-1;
            for(auto it : nums){
                if(mpp[it]==1){
                    track = max(track,it);
                }
            }
            return track;
        }
        else if(k==n){
            int maxi = *max_element(nums.begin(),nums.end());
            return maxi;
        }
        else{
            int ans=-1;
            if(mpp[nums[0]]==1) ans = max(nums[0],ans);
            if(mpp[nums[n-1]]==1) ans = max(nums[n-1],ans);
            return ans;
        }
        return -1;
    }
};