class Solution {
public:
    vector<vector<int>> dp;
    int minmoves(int egg, int f){
        if(egg==1 || f==1) return f;
        if(dp[egg][f]!=-1) return dp[egg][f];
        int ans = f;
        /*for(int i=1;i<=f;i++){
            // case 1: egg breaks:
            int c1 = minmoves(egg-1, i-1);
            //case 2: egg doesn't breaks:
            int c2 = minmoves(egg, f-i);

            ans = min(ans,1 + max(c1,c2));
        }*/

        int start=1;
        int end = f;
        while(start<=end){
            int mid = start+(end-start)/2;

            // case 1: egg breaks:
            int c1 = minmoves(egg-1, mid-1);
            //case 2: egg doesn't breaks:
            int c2 = minmoves(egg, f-mid);
            if(c1>=c2) end = mid-1;
            else start = mid+1;

            ans = min(ans,1 + max(c1,c2));
            
        }
        return dp[egg][f] = ans;
    }
    int superEggDrop(int k, int n) {
        dp.resize(k+1, vector<int>(n+1,-1));
        return minmoves(k,n);
    }
};