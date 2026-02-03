class Solution {
public:

    vector<vector<string>> ans;
    vector<string> arrangements;

    bool isValid(int r, int c){
        if(r==arrangements.size()) return false;

        for(int top=r;top>=0;top--){
            if(arrangements[top][c]=='Q') return false;
        }

        int startr = r; int startc = c;

        while(startr>=0 && startc!=arrangements.size()){
            if(arrangements[startr][startc]=='Q') return false;
            startr--, startc++;
        }

        startr=r, startc = c;

        while(startr>=0 && startc>=0){
            if(arrangements[startr][startc]=='Q') return false;
            startr--, startc--;
        }
        return true;
    }
void placingQueen(int r, int c, int placed, int n){
    if(placed==n){
        ans.push_back(arrangements);
        return ;
    }

    for(int curcol = c; curcol<n ;curcol++){
        if(isValid(r,curcol)){
            arrangements[r][curcol] = 'Q';
            placingQueen(r+1,0,placed+1, n);
            arrangements[r][curcol] = '.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        
        arrangements.resize(n,string(n,'.'));
        placingQueen(0,0,0,n);
        
        return ans;
    }
};