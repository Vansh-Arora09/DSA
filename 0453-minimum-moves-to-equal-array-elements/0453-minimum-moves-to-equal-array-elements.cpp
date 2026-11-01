class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        int mini = *min_element(nums.begin(), nums.end());
        for(int i : nums){
            ans+=(i-mini);
        }
        return ans;
    }
};