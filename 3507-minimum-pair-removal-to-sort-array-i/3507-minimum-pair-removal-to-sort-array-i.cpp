class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int opr=0;

        while(!is_sorted(nums.begin(),nums.end())){
            int tar = 0;
            int minsum = INT_MAX;

            for(int i=0;i<nums.size()-1;i++){

                int sum = nums[i]+nums[i+1];
                if(sum<minsum){
                    minsum = sum;
                    tar = i;
                }
            }
            opr++;
            nums[tar] = minsum;
            nums.erase(nums.begin()+tar+1);
        }
        return opr;
    }
};