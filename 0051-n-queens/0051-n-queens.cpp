class Solution {
public:
    vector<vector<string>> ans;
    unordered_set<int> cols, diag1, diag2;
    void solve(vector<string>&board, int row, int n){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            int d1 = row+col;
            int d2 = row-col;

            if(cols.count(col) || diag1.count(d1) || diag2.count(d2)) continue;

            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(d1);
            diag2.insert(d2);

            solve(board, row+1,n);
            board[row][col]='.';
            cols.erase(col);
            diag1.erase(d1);
            diag2.erase(d2);
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        solve(board,0,n);
        return ans; 
    }
};