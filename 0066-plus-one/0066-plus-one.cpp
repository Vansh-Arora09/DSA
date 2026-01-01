class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        int carry=1;
        for(int i=n-1;i>=0;i--){
            int sum = digits[i]+carry;
            digits[i] = sum%10;
            carry = sum/10;
        }
        if(carry>0){
            ans.push_back(carry);
        }
        for(int i=0;i<n;i++){
            ans.push_back(digits[i]);
        }
        return ans;
    }
};