class Solution {
public:
    vector<vector<int>> dp;
    int money(int l, int r){
        if(l==r) return 0;
        if( l==r-1) return l;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=1e8;
        for(int i= l+1;i<=r-1;i++){
            int guess1 = money(l, i-1);
            int guess2 = money(i+1, r);
            ans = min(ans, i + max(guess1, guess2));
        }
        dp[l][r] = ans;
        return ans;
    }
    int getMoneyAmount(int n) {
        dp.assign(n+1, vector<int>(n+1, -1));
        return money(1,n);
    }
};