class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> timerot(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    timerot[i][j] = 1e8;
                }
            }
        }

        while(q.size()){
            pair<int,int> curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            if(i+1<n && timerot[i+1][j]==1e8){
                timerot[i+1][j] = 1 + timerot[i][j];
                q.push({i+1, j});
            }
            if(j+1<m && timerot[i][j+1]==1e8){
                timerot[i][j+1] = 1 + timerot[i][j];
                q.push({i, j+1});
            }
            if(i-1>=0 && timerot[i-1][j]==1e8){
                timerot[i-1][j] = 1 + timerot[i][j];
                q.push({i-1, j});
            }
            if(j-1>=0 && timerot[i][j-1]==1e8){
                timerot[i][j-1] = 1 + timerot[i][j];
                q.push({i, j-1});
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans, timerot[i][j]);
            }
        }
        return (ans==1e8 ?  -1: ans);
    }
};