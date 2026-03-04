class Solution {
public:
    
    int numSpecial(vector<vector<int>>& mat) {
        int cnt=0;
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rsum(m,0), csum(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    rsum[i]++;
                    csum[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    if(rsum[i]==1 && csum[j]==1) cnt++;
                }
            }
        }
        return cnt;
    }
};