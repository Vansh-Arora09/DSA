class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i : nums){
            mpp[i]++;
        }
        int n = nums.size();
        vector<vector<int>> freq(n+1);
        for(auto [key,fr] : mpp){
            freq[fr].push_back(key);
        }

        for(int i=n;i>0;i--){
            while(k>0 && freq[i].size()!=0){
                ans.push_back(freq[i].back());
                k--;
                freq[i].pop_back();
            }
        }
        return ans;
    }
};