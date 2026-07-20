class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int tmp=grid[0][0];
        for(int x=0;x<k;x++){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    swap(tmp, grid[i][j]);
                }
            }
            grid[0][0] = tmp;
        }
        return grid;
    }
};