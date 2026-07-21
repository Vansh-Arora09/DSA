class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long left=0;
        long long right=0;
        long long curr=0;
        int ans=0;
        while(right<nums.size()){
            curr+=nums[right];

            if(nums[right]*(right-left+1)-curr > k){
                curr-=nums[left];
                left++;
            }
            ans = max(ans, (int)(right-left+1));
            right++;
        }
        return ans;
    }
};