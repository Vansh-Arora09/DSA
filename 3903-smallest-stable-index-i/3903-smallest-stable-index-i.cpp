class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> lft(n);
        lft[0] = nums[0];
        for(int i=1;i<n;i++){
            lft[i] = max(lft[i-1], nums[i]);
        }
        vector<int> rgt(n);
        rgt[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            rgt[i] = min(rgt[i+1], nums[i]);
        }

        for(int i=0;i<n;i++){
            if(abs(lft[i]-rgt[i])<=k){
                return i;
            }
        }
        return -1;

    }
};