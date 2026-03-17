class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]!=0 && i>0){
                    matrix[i][j]+= matrix[i-1][j];
                }
            }
            vector<int> curr(matrix[i].begin(), matrix[i].end());
            sort(curr.begin(), curr.end(), [](int a, int b){
                return a > b;
            });
            for(int j=0;j<curr.size();j++){
                ans = max(ans, curr[j] * (j+1));
            }
        }
        return ans;
    }
};