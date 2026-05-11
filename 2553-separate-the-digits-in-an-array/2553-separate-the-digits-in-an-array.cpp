class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        string s="";
        vector<int> res;
        for(int i : nums){
            string st = to_string(i);
            
            for(char c: st){
                res.push_back(c-'0');
            }
        }
        return res;
    }
};