class Solution {
public:

    void floodfill(int i, int j, vector<vector<char>>&grid, vector<vector<bool>>&vis){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j] || grid[i][j]=='0'){
            return;
        }
        vis[i][j] = true;
        floodfill(i+1,j ,grid,vis);
        floodfill(i-1,j,grid,vis);
        floodfill(i, j+1,grid, vis);
        floodfill(i, j-1, grid, vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==false){
                    floodfill(i,j, grid, visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};