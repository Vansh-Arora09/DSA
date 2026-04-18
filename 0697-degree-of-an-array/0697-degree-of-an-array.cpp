class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> first, last, cnt;
        int maxd=0;
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            if(first.find(val)==first.end()){
                first[nums[i]] = i;
            }
            last[nums[i]] = i;
            cnt[nums[i]]++;
            maxd = max(maxd, cnt[nums[i]]);
        }

        int mind = nums.size();
        for( auto [val, freq] : cnt){
            if(freq==maxd){
                int curr = last[val] - first[val]+1;
                mind = min(mind, curr);
            }
        }
        return mind;
    }
};