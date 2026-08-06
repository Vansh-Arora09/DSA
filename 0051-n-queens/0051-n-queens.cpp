class Solution {
public:
    vector<vector<string>> res;
    unordered_set<int> cols, diag1, diag2;
    void solve(int row, int n, vector<string>&board){
        if(row==board.size()){
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            int d1 = row-i;
            int d2 = row+i;

            if(cols.count(i) || diag1.count(d1) || diag2.count(d2)){
                continue;
            }

            board[row][i] = 'Q';
            cols.insert(i);
            diag1.insert(d1);
            diag2.insert(d2);

            solve(row+1,n,board);

            board[row][i] = '.';
            cols.erase(i);
            diag1.erase(d1);
            diag2.erase(d2);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        solve(0, n, board);
        return res;
    }
};