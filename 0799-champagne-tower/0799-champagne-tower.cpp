class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(101,0.0);
        dp[0] = (double)poured;

        for(int i=0;i<query_row;i++){
            vector<double> nxt_ros(101,0.0);
            for(int j=0;j<=i;j++){
                if(dp[j]>1.0){
                    double spill = (dp[j]-1.0)/2.0;
                    nxt_ros[j]+=spill;
                    nxt_ros[j+1]+=spill;
                }
            }
            dp = nxt_ros;
        }
        return min(1.0, dp[query_glass]);
    }
};