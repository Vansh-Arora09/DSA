class Solution {
public:
    bool areSimilar(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> mat = grid;
        while(k--){
            for(int i=0;i<m;i+=2){
                int first = mat[i][0];
                for(int j=1;j<n;j++){
                    mat[i][j-1] = mat[i][j];
                }
                mat[i][n-1] = first;
            }
            for(int i=1;i<m;i+=2){
                int last = mat[i][n-1];
                for(int j=n-1;j>0;j--){
                    mat[i][j] = mat[i][j-1];
                }
                mat[i][0] = last;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=grid[i][j]){
                    return false;
                }
            }
        }
        return true;
    }

     
};