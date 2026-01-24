class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                nums[i] = 0;
            }
            else{
                nums[i] = 1;
            }
        }
        unordered_map<int,int> mpp;
        int sum=0;
        int cnt=0;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];

            int rem = sum -k;
            if(mpp.find(rem)!= mpp.end()){
                cnt+=mpp[rem];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};