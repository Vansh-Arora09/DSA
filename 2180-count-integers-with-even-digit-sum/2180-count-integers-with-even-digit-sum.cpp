class Solution {
public:
    int countEven(int num) {
        int cnt=0;
        for(int i=1;i<=num;i++){
            int sum=0;
            int tmp=i;
            while(tmp>0){
                int rem = tmp%10;
                sum+=rem;
                tmp/=10;
            }
            if(sum%2==0) cnt++;
        }
        return cnt;
    }
};