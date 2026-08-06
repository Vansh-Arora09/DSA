class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=n+10;i++){
            int tmp=i;
            int prod=1;
            while(tmp>0){
                prod*=(tmp%10);
                tmp/=10;
            }
            if(prod%t == 0) return i;
        }
        return -1;
    }
};