class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            int bits = log2(i);
            int range = pow(2,bits);
            ans.push_back(1+ans[i - range]);
        }    
        return ans;
    }
};