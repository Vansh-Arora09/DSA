class Solution {
public:

    int getrec(vector<vector<int>>& p, int x1, int y1, int x2, int y2){
        return p[x2][y2] - p[x1-1][y2] - p[x2][y1-1] + p[x1-1][y1-1];
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> presum(m+1,vector<int>(n+1));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                presum[i][j] = presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1] + mat[i-1][j-1];
            }
        }

        int r = min(m,n);
        int ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                for(int c=ans+1;c<=r;c++){
                    if(i+c-1 <=m && j+c-1 <=n && getrec(presum,i,j,i+c-1, j+c-1) <=threshold){
                        ans++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};