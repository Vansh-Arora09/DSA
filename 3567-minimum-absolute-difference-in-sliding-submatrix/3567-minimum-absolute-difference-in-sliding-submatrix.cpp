class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1, 0));

        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){

                set<int> uniq;
                for(int r=i;r<i+k;r++){
                    for(int c=j;c<j+k;c++){
                        uniq.insert(grid[r][c]);
                    }
                }
                vector<int> sub(uniq.begin(), uniq.end());
                if(sub.size()<2){
                    ans[i][j]=0;
                    continue;
                }
                sort(sub.begin(), sub.end());

                int res = INT_MAX;
                for(int id=1;id<sub.size();id++){
                    int mindiff = sub[id] - sub[id-1];
                    res = min(res, mindiff);
                    if(res==0) break; // we can't get smaller than this
                }

                ans[i][j] = res;
            }
        }
        return ans;
    }
};