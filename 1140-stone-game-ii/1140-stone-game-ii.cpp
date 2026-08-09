class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> suff;
    int solve(int i, int m){
        if(i+2*m>=n) return suff[i]; // means we can grab all the piles at once

        if(dp[i][m]!=0) return dp[i][m];
        int maxStone = 0;
        for(int x=1;x<=2*m;x++){
            int nextM = max(x,m);
            int remStone = suff[i] - solve(i+x, nextM);
            maxStone = max(maxStone, remStone);
        }
        return dp[i][m] = maxStone;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suff.resize(n+1,0);
        dp.assign(101, vector<int>(101,0));
        for(int i=n-1;i>=0;i--){
            suff[i] = suff[i+1]+piles[i];
        }
        return solve(0, 1); // solve(i,M);
    }
};