class Solution {
public:
    int rowc,colc;
    vector<vector<int>> grid;
    vector<vector<bool>> vis;

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    bool cancross(int day, vector<vector<int>>& cells){
        grid.assign(rowc,vector<int>(colc,0));
        queue<pair<int,int>> q;
        vis.assign(rowc, vector<bool>(colc,false));

        for(int i=0;i<day;i++){
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }
        for(int i=0;i<colc;i++){
            if(grid[0][i]==0){
                q.push({0,i});
                vis[0][i] = true;
            }
        }

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            if(x == rowc-1){
                return true;
            }

            for(int d = 0;d<4;d++){
                int r = x + dx[d];
                int c = y + dy[d];

                if(r>=0 && r<rowc && c>=0 && c<colc && !vis[r][c] && grid[r][c]==0 ){
                    vis[r][c]  = true;
                    q.push({r,c});
                }

            }
        }
        return false;
    } 

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        rowc = row;
        colc = col;

        int left = 0, high = row*col, ans=0;
        while(left<=high){
            int mid = left + (high-left)/2;

            if(cancross(mid,cells)){
                ans = mid;
                left = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
        
    }
};