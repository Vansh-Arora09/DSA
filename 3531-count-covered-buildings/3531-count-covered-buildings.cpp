class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> maxrow(n+1);
        vector<int> minrow(n+1,n+1);
        vector<int> maxcol(n+1);
        vector<int> mincol(n+1,n+1);

        for(auto p : buildings){
            int x = p[0],y = p[1];
            maxrow[y] = max(maxrow[y],x);
            minrow[y] = min(minrow[y],x);
            maxcol[x] = max(maxcol[x],y);
            mincol[x] = min(mincol[x],y);
        }

        int res=0;
        for(auto p : buildings){
            int x = p[0],y = p[1];
            if(x > minrow[y] && x < maxrow[y] && y>mincol[x] && y<maxcol[x]){
                res++;
            }
        }
        return res;
    }
};