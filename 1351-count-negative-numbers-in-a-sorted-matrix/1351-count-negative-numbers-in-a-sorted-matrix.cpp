class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int col= 0;
        int row = m-1;
        int cnt=0;
        while(row>=0 && col<n){
            if(grid[row][col]<0){
                cnt+=(n-col);
                row--;
            }
            else{
                col++;
            }
        }
        return cnt;
    }
};