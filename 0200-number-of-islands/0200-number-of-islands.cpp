class Solution {
public:

    void dfs(int i, int j, int m, int n, vector<vector<bool>>&vis, vector<vector<char>>&grid){
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || grid[i][j]=='0'){
            return;
        }
        vis[i][j]=true;
        dfs(i+1,j,m,n,vis,grid);
        dfs(i-1,j,m,n,vis,grid);
        dfs(i,j-1,m,n,vis,grid);
        dfs(i,j+1,m,n,vis,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt=0;
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,m,n,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};