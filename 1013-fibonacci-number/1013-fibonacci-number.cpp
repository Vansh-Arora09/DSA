class Solution {
public:
    int fibb(int n , vector<int>&m){
        if(m[n]!=-1){
            return m[n];
        }
        m[n] = fibb(n-1, m) + fibb(n-2 , m);
        return m[n];
    }
    int fib(int n) {
        if(n<=1) return n;
        vector<int> m(n+1,-1);
        m[0]=0;
        m[1]=1;
        return fibb(n,m);
    }
};