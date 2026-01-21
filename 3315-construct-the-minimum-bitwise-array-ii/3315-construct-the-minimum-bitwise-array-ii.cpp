class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int n : nums){
            if(n==2){
                ans.push_back(-1);
            }
            else{
                int temp=n;
                int bit = 0;
                while((temp&1)!=0){
                    temp>>=1;
                    bit++;
                }
                int res = n^(1 << (bit -1));
                ans.push_back(res);
            }
            
        }
        return ans;
    }
};