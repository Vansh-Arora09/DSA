class Solution {
public:
    bool isValid(vector<vector<char>>&board, int row, int col, char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c) return false;
        }
        for(int j=0;j<9;j++){
            if(board[row][j]==c) return false;
        }

        int r = row-row%3;
        int cl = col-col%3;

        for(int i=r;i<r+3;i++){
            for(int j=cl;j<cl+3;j++){
                if(board[i][j]==c){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>&board){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(board, row, col, c)){
                            board[row][col]=c;
                            if(solve(board)) return true;

                            board[row][col]='.';
                        }

                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};