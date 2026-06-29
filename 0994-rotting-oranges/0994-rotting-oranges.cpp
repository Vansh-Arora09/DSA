class Solution {
public:
    void rotten(vector<vector<int>>&grid, int i, int j){
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int minutes=0;
        if(fresh==0) return 0;

        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,-1,1};

        while(!q.empty()){
            int size = q.size();
            bool get_rotten=false;

            for(int i=0;i<size;i++){
                auto [r,c] = q.front();
                q.pop();

                for(int d=0;d<4;d++){
                    int nrow = r + drow[d];
                    int ncol = c + dcol[d];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        fresh--;
                        get_rotten=true;
                    }
                }
            }
            if(get_rotten) minutes++;
        }
        return fresh==0 ? minutes : -1;
    }
};