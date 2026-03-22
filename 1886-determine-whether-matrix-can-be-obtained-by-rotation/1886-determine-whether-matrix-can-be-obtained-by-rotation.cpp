class Solution {
public:
    void rotate(vector<vector<int>> &mat){
        int m = mat.size();
        int n = mat[0].size();

        for(int i=0;i<m-1;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        for(int i=0;i<4;i++){
            if(target==mat){
                return true;
            }
            rotate(mat);
        }
        return false;
    }
};