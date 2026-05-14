class Solution {
public:
    bool isGood(vector<int>& nums) {

        int n = nums.size();
        int base = n-1;
        if(base <=0) return 0;
        vector<int> cnt(n,0);

        for(int i=0;i<n;i++){
            if(nums[i]<1 || nums[i]>base) return false;
            cnt[nums[i]]++;
        }

        for(int i=1;i<base;i++){
            if(cnt[i]!=1) return false;
        }
        return cnt[base]==2;
    }
};