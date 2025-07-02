class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool fl1 = false;
        bool fl2 = false;
        if(is_sorted(nums.begin(),nums.end())){
            fl1=true;
        }
        else if(is_sorted(nums.begin(),nums.end(),greater<int>())){
            fl2=true;
        }
        if(fl1 || fl2){
            return true;
        }
        else{
            return false;
        }
    }
};