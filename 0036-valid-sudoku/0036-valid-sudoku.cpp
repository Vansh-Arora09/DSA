class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_set<int> row[9], col[9], box[9];
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                char val = board[r][c];
                if(val=='.') continue;
                int box_ind = (r/3) *3 + (c/3);
                if(row[r].count(val) || col[c].count(val) || box[box_ind].count(val)){
                    return false; // not possible, duplicate already exists.
                }
                row[r].insert(val);
                col[c].insert(val);
                box[box_ind].insert(val);
            }
        }
        return true;
    }
};