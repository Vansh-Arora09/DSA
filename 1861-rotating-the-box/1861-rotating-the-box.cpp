class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> box(n, vector<char>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                box[i][j] = boxGrid[m-1-j][i];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=n-1;i>=0;i--){
                if(box[i][j]=='.'){
                    int stone = -1;

                    for(int k = i-1;k>=0;k--){
                        if(box[k][j]=='*'){
                            break;
                        }
                        if(box[k][j]=='#'){
                            stone = k;
                            break;
                        }
                    }
                    if(stone!=-1){
                        box[stone][j] = '.';
                        box[i][j] = '#';
                    }
                }
            }
        }
        return box;
    }
};