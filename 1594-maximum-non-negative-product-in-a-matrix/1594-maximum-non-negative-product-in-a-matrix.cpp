class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int mod = 1e9+7;
        vector<vector<long long>> maxv(m, vector<long long>(n));
        vector<vector<long long>> minv(m, vector<long long>(n));

        maxv[0][0] = minv[0][0] = grid[0][0];
        for(int i=1;i<n;i++){
            maxv[0][i] = minv[0][i] = maxv[0][i-1]*grid[0][i];
        }

        for(int i=1;i<m;i++){
            maxv[i][0] = minv[i][0] = maxv[i-1][0]*grid[i][0];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]>=0){
                    maxv[i][j] = max(maxv[i][j-1], maxv[i-1][j])*grid[i][j];
                    minv[i][j] = min(minv[i-1][j], minv[i][j-1])*grid[i][j];
                }
                else{
                    maxv[i][j] = min(minv[i-1][j], minv[i][j-1])*grid[i][j];
                    minv[i][j] = max(maxv[i-1][j], maxv[i][j-1])*grid[i][j];
                }
            }
        }


        if(maxv[m-1][n-1]<0){
            return -1;
        }
        return maxv[m-1][n-1]%mod;
    }
};