class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> index;
        int n = nums.size();
        for(int i=0;i<n;i++){
            index.push_back({nums[i],i});
        }

        sort(index.begin(),index.end());

        vector<pair<int,int>> kElem(index.begin()+n-k,index.end());
        sort(kElem.begin(),kElem.end(), [] (const pair<int,int>&a,const pair<int,int>&b){
            return a.second<b.second;
        });

        vector<int> ans;
        for(int i=0;i<kElem.size();i++){
            ans.push_back(kElem[i].first);
        }
        return ans;
    }
};