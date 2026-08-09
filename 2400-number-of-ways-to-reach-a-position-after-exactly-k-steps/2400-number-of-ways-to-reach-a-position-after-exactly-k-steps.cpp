class Solution {
public:
    vector<vector<int>> dp;
    const int mod=1e9+7;
    int target;
    int ways(int srt, int k){
        if(k==0) return srt==target? 1 : 0;
        if(abs(target-srt)>k){
            return 0;
        }
        int sft = srt+1000;
        if(dp[sft][k]!=-1) return dp[sft][k];
        int take1 = ways(srt-1,k-1);
        int take2 = ways(srt+1, k-1);

        return dp[sft][k]=(take1+take2)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        dp.assign(3005, vector<int>(1005,-1));
        target = endPos;
        return ways(startPos,k);

    }
};