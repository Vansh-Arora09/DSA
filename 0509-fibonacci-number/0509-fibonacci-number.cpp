class Solution {
public:
int dp[10006] = {0};
    int fib(int n) {
        if(n<1) return 0;
        if(n==1 || n==2) return 1;
        if(dp[n]!=0){
            //already calculated the state
            return dp[n];
        }
        dp[n] = fib(n-1)+fib(n-2);

        return dp[n];
    }
};