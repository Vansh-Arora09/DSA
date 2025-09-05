class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=1;i<=60;i++){
            long long rem = (long long)num1-(long long)i*num2;
            if(rem<i) continue;

            int cnt1 = 0;
            long long temp = rem;
            while(temp>0){
                if(temp%2==1) cnt1++;
                temp=temp/2;
            }
            if(cnt1<=i && i<=rem){
                return i;
            }
        }
        return -1;
    }
};