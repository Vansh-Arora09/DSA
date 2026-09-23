class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(),0);

        int tarRem = sum-x;
        if(tarRem==0) return nums.size();
        if(tarRem<0) return -1;
        int left=0;
        int ans=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
            while(ans>tarRem){
                ans-=nums[left];
                left++;
            }
            if(ans==tarRem){
                maxi = max(maxi, (i-left+1));
            }
            
        }
        if(maxi==0) return -1;
        return nums.size()-maxi;
    }
};