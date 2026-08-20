class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a1,a2;
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        int loop = nums.size()-2;
        for(int i=2;i<=loop+1;i++){
            if(a1[a1.size()-1]>a2[a2.size()-1]){
                a1.push_back(nums[i]);
            }
            else{
                a2.push_back(nums[i]);
            }
        }
        vector<int> res;
        for(int i : a1){
            res.push_back(i);
        }
        for(int i : a2) res.push_back(i);
        return res;
    }
};