class Solution {
public:
    int fib(int row,int col){
        long long res = 1;
        for(int i=0;i<col;i++){
            res =  res*(row-i);
            res = res/(i+1);
        }
        return (int)res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                temp.push_back(fib(i,j));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};