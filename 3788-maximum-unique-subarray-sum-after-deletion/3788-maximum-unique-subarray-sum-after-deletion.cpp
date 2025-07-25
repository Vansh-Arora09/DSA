class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();

        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] > max)
                max = nums[i];
        }
        if (max < 0)
            return max;

        unordered_set<int> unique(nums.begin(), nums.end());
        int sum = 0;
        for (int val : unique) {
            if (val >= 0)
                sum += val;
        }
        return sum;
    }
};