class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int rem=0;
        int len=1;
        while(len<=k){
            int n = rem * 10 +1;
            rem = n % k;
            
            if(rem==0){
                return len;
            }
            len+=1;

        }
        return -1;
    }
};