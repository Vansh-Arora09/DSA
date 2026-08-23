class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int tmp=n;
        int prod=1;
        while(tmp>0){
            sum+=(tmp%10);
            prod*=(tmp%10);
            tmp/=10;
        }
        int total=prod+sum;
        return n%total==0;

    }
};