class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int n = points.size();
        for(int i=0;i<n-1;i++){
            int x = points[i][0];
            int y = points[i][1];
            int trx = points[i+1][0];
            int ty = points[i+1][1];
            ans+= max(abs(trx-x),abs(ty-y));
        }
        return ans;
    }
};