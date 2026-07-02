class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> maxihealth(m, vector<int>(n, -1));

        deque<vector<int>> dq;

        int start = health - grid[0][0];

        if(start <=0) return false;

        maxihealth[0][0] = start;
        dq.push_front({0, 0, start});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!dq.empty()){
            auto curr = dq.front();
            dq.pop_front();

            int r = curr[0];
            int c = curr[1];
            int h = curr[2];
            if(r==m-1 && c==n-1 && h>=1){
                return true;
            }

            if(h < maxihealth[r][c]) continue;

            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nc<n && nr<m && nc>=0){
                    int nxt = h - grid[nr][nc];

                    if(nxt > maxihealth[nr][nc] && nxt >=1){
                        maxihealth[nr][nc] = nxt;
                        if(grid[nr][nc]==0) dq.push_front({nr, nc, nxt});

                        else{
                            dq.push_back({nr, nc, nxt});
                        }
                    }
                }
            }
        }
        return false;

    }
};