class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        /* -------using sorting ----------


        vector<pair<int,int>> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back({nums[i],i});
        }
        sort(ans.begin(),ans.end());

        int i=0;
        int j= nums.size()-1;
        while(i<j){
            if(ans[i].first + ans[j].first == target){
                return {ans[i].second, ans[j].second};
            }

            else if(ans[i].first + ans[j].first < target){
                i++;
            }
            else j--;
        }
        return {-1,-1};  */

        // using hashmap------

        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){

            int rem = target - nums[i];

            if(mpp.find(rem)!=mpp.end()){
                return {mpp[rem], i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};