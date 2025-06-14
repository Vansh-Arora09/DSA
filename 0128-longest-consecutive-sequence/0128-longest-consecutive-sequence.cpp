class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int last_sm = INT_MIN;
        int cnt = 0;
        int longest = 0;
        for(int i=0;i<n;i++){
            if(nums[i]-1 == last_sm){
                cnt++;
                last_sm = nums[i];
            }
            else if(nums[i]!=last_sm){
                cnt=1;
                last_sm = nums[i];
            }
            longest = max(longest,cnt);
        }
        return longest;
    }
};