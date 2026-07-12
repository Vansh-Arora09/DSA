class Solution {
public:
    void backtrack(vector<vector<int>>&res, vector<int>& cur, vector<int>&nums, vector<bool>&vis){
        if(cur.size()==nums.size()){
            res.push_back(cur);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i] = true;
                cur.push_back(nums[i]);
                backtrack(res, cur, nums, vis);

                cur.pop_back();
                vis[i]=false;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        vector<bool> vis(nums.size(), 0);
        backtrack(result, cur, nums, vis);
        return result;
    }
};