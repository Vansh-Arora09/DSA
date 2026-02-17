class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum=0, sqrsum =0;
        long long n = grid.size();
        long long total = n*n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+= grid[i][j];
                sqrsum+=(grid[i][j]* grid[i][j]);
            }
        }

        long long sumdiff = sum - total * (total+1)/2;
        long long sqrdiff = sqrsum - total * (total+1) * (2*total+1)/6;

        int repeat = (sqrdiff / sumdiff + sumdiff)/2;
        int missing = (sqrdiff/ sumdiff - sumdiff)/2;

        return {repeat,missing};
    }
};