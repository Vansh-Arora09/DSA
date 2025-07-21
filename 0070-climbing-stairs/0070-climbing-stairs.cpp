class Solution {
public:
    int stairs(int n, vector<int>&m){
        if(m[n]!=-1) return m[n];
        m[n] = stairs(n-1,m) + stairs(n-2,m);
        return m[n];
    }
    int climbStairs(int n) {
        vector<int> m(n+1,-1);
        m[0]=1;
        m[1] =1;
        return stairs(n,m);
    }
};