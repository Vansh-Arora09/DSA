class Solution {
public:

    bool isPrime(int i){
        if(i<=1) return false;
        if(i<=3) return true;
        if(i%2==0 || i%3==0) return false;
        for(int j=5;j*j<=i;j+=6){
            if(i%j==0 || i%(j+2)==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            ans+= isPrime(__builtin_popcount(i));
        }
        return ans;
    }
};