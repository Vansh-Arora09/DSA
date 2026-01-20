class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]==2) ans.push_back(-1);
            else{
                for(int x=0;x<nums[i];x++){
                    if((x|(x+1)) == nums[i]){
                        ans.push_back(x);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};