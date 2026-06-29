class Solution {
public:
    int find(vector<int>&nums, int target, bool fst){
        int low = 0;
        int high = nums.size()-1;
        int result=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                result = mid;
                if(fst){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};

        int first = find(nums, target, true);
        int last = find(nums,target, false);

        return {first, last};
    }
};