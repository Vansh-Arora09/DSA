class Solution {
public:
    int partsum=0;

    bool rec(vector<int>&nums, int k, int cursum, vector<bool>&vis, int idx){
        if(k<=1) return true;
        if(idx==nums.size()) return false;
        if(partsum==cursum){
            return rec(nums, k-1, 0, vis, 0);
        }

        for(int i=idx;i<nums.size();i++){
            if(nums[i]+cursum > partsum){
                break;
            }
            if(vis[i]) continue;

            vis[i] = true;
            if(rec(nums,k,cursum+nums[i], vis, i+1)){
                return true;
            }
            vis[i] = false;
        }

        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        if(total_sum%k) return false;
        partsum = total_sum/k;

        vector<bool> vis(nums.size(), false);
        sort(nums.begin(),nums.end());
        return rec(nums,k,0,vis,0);
        
    }
};