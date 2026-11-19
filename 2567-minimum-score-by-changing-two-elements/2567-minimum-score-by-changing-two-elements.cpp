class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        // Sort the array
        sort(nums.begin(), nums.end());

        // Three possible cases
        int case1 = nums[n - 3] - nums[0];

        int case2 = nums[n - 2] - nums[1];

        int case3 = nums[n - 1] - nums[2];

        // Return the minimum among all three cases
        return min({case1, case2, case3});
    }
};