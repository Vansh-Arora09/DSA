class Solution {
public:
    int getSum(int n){
        int ans=0;
        while(n>0){
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i] = getSum(nums[i]);
        }
        int ans = *min_element(nums.begin(),nums.end());
        return ans;
    }
};