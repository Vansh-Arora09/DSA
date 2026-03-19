class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> tmp(m, vector<int>(n));
        vector<vector<int>> hasX(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]=='X'){
                    tmp[i][j] = 1;
                    hasX[i][j]=1;
                }
                else if(grid[i][j]=='Y'){
                    tmp[i][j] = -1;
                }
                else{
                    tmp[i][j]=0;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0){
                    tmp[i][j]+= tmp[i-1][j];
                    hasX[i][j]+= hasX[i-1][j];
                }
                if(j>0){
                    tmp[i][j]+= tmp[i][j-1];
                    hasX[i][j]+= hasX[i][j-1];
                }
                if(i>0 && j>0){
                    tmp[i][j]-= tmp[i-1][j-1];
                    hasX[i][j]-= hasX[i-1][j-1];
                }

                if(tmp[i][j]==0 && hasX[i][j]>0) cnt++;
            }
        }
        return cnt;
    }
};