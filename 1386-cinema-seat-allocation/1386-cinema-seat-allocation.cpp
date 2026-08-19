class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> rsv;

        for(auto seat : reservedSeats){
            int row = seat[0];
            int col = seat[1];

            if(col>=2 && col<=9){
                rsv[row]|= (1 << (col-2));
            }
        }

        int total = (n - rsv.size())*2;
        int left=15;
        int right = 240;
        int mid = 60;
        for(auto [row, seat] : rsv){
            bool leftM = (seat&left)==0;
            bool rightM = (seat&right)==0;
            bool midM = (seat&mid)==0;
            if(leftM && rightM) total+=2;
            else if(leftM || rightM || midM) total+=1;
        }
        return total;
    }
};