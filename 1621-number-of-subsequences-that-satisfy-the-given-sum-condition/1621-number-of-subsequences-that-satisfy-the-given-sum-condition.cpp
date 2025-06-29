class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        const int mod = 1e9+7;
        sort(nums.begin(),nums.end());
        vector<int> ans(n+1);
        ans[0]=1;
        for(int i=1;i<=n;i++){
            ans[i] = (ans[i-1]*2)%mod;
        }
        int res = 0;
        int left=0;
        int right=n-1;
        while(left<=right){
            if(nums[left]+nums[right] <=target){
                res = (res+ ans[right-left])%mod;
                left++;
            }
            else{
                right--;
            }
        }
        return res;
    }
};