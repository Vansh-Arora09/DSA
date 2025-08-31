class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};

        int n = matrix[0].size();
        int m = matrix.size();     
        vector<int> res(m*n);
        int row=0;
        int col=0;
        for(int i=0;i<m*n;i++){
            res[i] = matrix[row][col];

            if((row+col)%2==0){
                if(col==n-1) row++;
                else if(row==0) col++;
                else{
                    row--;
                    col++;
                }
            }else{
                if(row==m-1) col++;
                else if(col==0) row++;
                else{
                    row++;
                    col--;
                }
            }
        }
        return res;

    }
};