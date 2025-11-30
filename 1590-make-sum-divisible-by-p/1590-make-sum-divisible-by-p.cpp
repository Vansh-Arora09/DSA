class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum = (sum+nums[i])%p;
        }
        if(sum%p==0) return 0;
        int cursum=0;
        int minlen=n;
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        for(int i=0;i<n;i++){
            cursum = (cursum+nums[i])%p;

            int needed = (cursum-sum +p)%p;

            if(mpp.find(needed)!=mpp.end()){
                minlen = min(minlen,i-mpp[needed]);
            }
            mpp[cursum]=i;
        }
        return minlen==n?-1:minlen;



    }
};