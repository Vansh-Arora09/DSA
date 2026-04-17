class Solution {
public:
    int rev(int n){
        int rev=0;
        while(n>0){
            int rem = n%10;
            rev = (rev*10)+rem;
            n/=10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            
            if(mpp.count(curr)){
                ans = min(ans, i - mpp[curr]);
            }
            mpp[rev(curr)] = i;
        }
        return (ans==INT_MAX) ? -1: ans;
    }
};