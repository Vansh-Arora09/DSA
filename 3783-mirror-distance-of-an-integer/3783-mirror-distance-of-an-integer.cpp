class Solution {
public:
    int mirrorDistance(int n) {
        int tmp=n;
        int rev=0;
        while(tmp>0){
            rev = (rev*10)+(tmp%10);
            tmp/=10;
        }
        return abs(rev-n);
    }
};