class Solution {
public:
    vector<vector<int>> ans;
    void genSub(vector<int>& nums, int idx, vector<int> cursub){
        if(idx>=nums.size()){
            ans.push_back(cursub);
            return;
        }
        genSub(nums,idx+1,cursub);

        cursub.push_back(nums[idx]);

        genSub(nums, idx+1, cursub);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        genSub(nums,0,{});
        return ans;
        
    }
};