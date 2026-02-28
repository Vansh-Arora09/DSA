class Solution {
public:
    int concatenatedBinary(int n) {
        long long res=0;
        int mod = 1e9+7;

        int bitlength=0;

        for(int i=1;i<=n;i++){
            if((i & (i-1))==0) bitlength++;

            res = ((res<<bitlength) | i) % mod;
        }
        return res;
    }
};