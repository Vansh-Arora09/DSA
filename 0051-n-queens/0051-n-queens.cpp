class Solution {
public:
    void backtrack(int n, int row, 
                vector<bool>& columns, vector<bool>& diag1, vector<bool>& diag2,
                vector<string>& board,
                vector<vector<string>>& result){
                    if(row == n){
                        result.push_back(board);
                        return;
                    }
                    
                    for(int col = 0; col < n; col++){
                        if(columns[col] || diag1[row - col + n - 1] || diag2[row + col]) continue;
                        
                        board[row][col] = 'Q';
                        columns[col] = diag1[row - col + n - 1] = diag2[row + col] = true;
                        
                        backtrack(n, row + 1, columns, diag1, diag2, board, result);
                        
                        board[row][col] = '.';
                        columns[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
                    }
                }

    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> columns(n, false);
        vector<bool> diag1(2*n-1, false);
        vector<bool> diag2(2*n-1, false);
        backtrack(n, 0, columns, diag1, diag2, board, result);
        return result;
    }
};