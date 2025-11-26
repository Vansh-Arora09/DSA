const int MOD = 1e9+7;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        auto dp = vector(m+1, vector(n+1,vector<long long>(k)));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1 && j==1){
                    dp[i][j][grid[0][0]%k]=1;
                    continue;
                }

                int value = grid[i-1][j-1]%k;
                for(int r=0;r<k;r++){
                    int pmod = (r - value + k) % k;
                    dp[i][j][r] = (dp[i-1][j][pmod] + dp[i][j-1][pmod])% MOD;
                }
            }
        }
        return dp[m][n][0];
    }
};