class Solution {
public:
    unordered_set<int> cols, diag1, diag2;
    int totalNQueens(int n, int row=0) {
        if(row==n){
            return 1;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            int d1 = row-i;
            int d2 = row+i;

            if(cols.count(i) || diag1.count(d1) || diag2.count(d2)){
                continue;
            }

            cols.insert(i);
            diag1.insert(d1);
            diag2.insert(d2);

            cnt+=totalNQueens(n,row+1);
            cols.erase(i);
            diag1.erase(d1);
            diag2.erase(d2);

        }
        return cnt;
    }
};