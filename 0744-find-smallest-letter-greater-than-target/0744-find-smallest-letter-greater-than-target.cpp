class Solution {
public:
    char nextGreatestLetter(vector<char>& nums, char target) {
        int n = nums.size();
        int start=0;
        int end = n-1;
        int ans=0;
        while(start<=end){
            int mid = start+(end - start)/2;

            
            if(nums[mid]-'a' > target-'a'){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return nums[ans];
    }
};