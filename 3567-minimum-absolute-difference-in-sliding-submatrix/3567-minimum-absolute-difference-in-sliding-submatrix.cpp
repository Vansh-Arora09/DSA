class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> res(m-k+1, vector<int>(n-k+1,0));

        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){

                set<int> uniq;
                for(int r=i;r<i+k;r++){
                    for(int c=j;c<j+k;c++){
                        uniq.insert(grid[r][c]);
                    }
                }

                vector<int> slid(uniq.begin(),uniq.end());
                if(slid.size()<2){
                    res[i][j]=0;
                    continue;
                }
                int mindiff=INT_MAX;
                for(int idx=1;idx<slid.size();idx++){
                    mindiff = min(mindiff, slid[idx]-slid[idx-1]);
                    if(mindiff==0) break;
                }

                res[i][j] = mindiff;
            }
        }
        return res;
    }
};