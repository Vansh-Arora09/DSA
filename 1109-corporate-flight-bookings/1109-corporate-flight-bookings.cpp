class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n);
        for(int i=0;i<bookings.size();i++){
            int fst = bookings[i][0];
            int lst = bookings[i][1];
            int seat = bookings[i][2];

            diff[fst-1]+=seat;
            if(lst!=n) diff[lst]-=seat;
        }
        for(int i=1;i<diff.size();i++){
            diff[i]+= diff[i-1];
        }
        return diff;

    }
};