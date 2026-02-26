class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        int clos = nums[0]+nums[1]+nums[2];
        for(int k=0;k<n-2;k++){

            if(k>0 && nums[k]==nums[k-1]) continue;

            int i = k+1;
            int j = n-1;

            while(i<j){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(target-sum) < abs(target-clos)){
                    clos = sum;
                }
                if(sum==target) return target;
                else if(sum < target) i++;
                else j--;
            }
        }
        return clos;
    }
};