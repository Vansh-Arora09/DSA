class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int cnt=0;
        int min_value = INT_MAX;
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    cnt++;
                }
                min_value = min(min_value,abs(matrix[i][j]));
            }
        }
        if(cnt%2!=0){
            sum-= 2*min_value;
        }
        
        return sum;
    }
};