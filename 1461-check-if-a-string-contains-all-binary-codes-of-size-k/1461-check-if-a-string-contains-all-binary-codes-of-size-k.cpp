class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<k) return false;
        int n = s.length();
        unordered_map<string,int> mpp;
        for(int i=0;i<=n-k;i++){
            string tmp= s.substr(i, k);
            
            mpp[tmp]++;
        }
        long long pwr = pow(2,k);
        if(mpp.size()<pwr) return false;
        return true;
    }
};