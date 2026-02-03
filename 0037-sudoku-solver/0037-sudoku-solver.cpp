class Solution {
public:
    vector<vector<char>> ans;
    bool isValid(int r, int c, char num, vector<vector<char>>& sudoku) {
        if(sudoku[r][c] != '.') return false;
        for(int curr = 0; curr < 9; curr++) {
            if(sudoku[curr][c] == num) return false;
            if(sudoku[r][curr] == num) return false;
        }
        // Defining boundary for boxes
        int startRow = (r / 3) * 3;
        int startCol = (c / 3) * 3;

        for(int i = startRow; i < startRow + 3; i++) {
            for(int j = startCol; j < startCol + 3; j++) {
                if(sudoku[i][j] == num) return false;
            }
        }
        return true;
    }

    void solver(int r, int c, int emptyCell, vector<vector<char>>& sudoku) {
        if(emptyCell == 0) {
            ans = sudoku;
            return;
        }
    
        if(sudoku[r][c] != '.') {
            solver(r + (c + 1 == 9), (c + 1) % 9, emptyCell, sudoku);
        }
        for(char i = '1'; i <= '9'; i++) {
            
            if(isValid(r, c, i, sudoku)) {
                sudoku[r][c] = i;
                solver(r + (c + 1 == 9), (c + 1) % 9, emptyCell - 1, sudoku);
                sudoku[r][c] = '.';
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        int emptyCell = 0;
        for(int i = 0; i < 9; i++) for(int j = 0; j < 9; j++) emptyCell += (board[i][j] == '.');
        solver(0, 0, emptyCell, board);
        board = ans;
    }
};