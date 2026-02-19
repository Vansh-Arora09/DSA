class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> idx;
        for(int i=0;i<nums.size();i++){
            idx.push_back({nums[i],i});
        }
        sort(idx.begin(), idx.end());
        int i=0;
        int j=nums.size()-1;

        while(i<j){
            if(idx[i].first + idx[j].first == target) return {idx[i].second , idx[j].second};

            else if((idx[i].first +  idx[j].first) < target) i++;
            else j--;
        }
        return {};
    }
};