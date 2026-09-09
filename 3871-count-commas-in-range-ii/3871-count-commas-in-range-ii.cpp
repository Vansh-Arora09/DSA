class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;

        for(long long thres=1000;thres<=n;thres*=1000){
            ans+= n-thres+1;
        }
        return ans;
    }
};