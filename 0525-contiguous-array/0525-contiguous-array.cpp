class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mpp;
        mpp[0] = -1;

        int maxlen=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+= (nums[i]==1 ? 1 : -1);
            if(mpp.find(cnt)!=mpp.end()){
                maxlen = max(maxlen, i - mpp[cnt]);
            }
            else{
                mpp[cnt] = i;
            }
        }
        return maxlen;
    }

};