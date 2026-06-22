class Solution {
public:
    int pivotInteger(int n) {
        int cal = n*(n+1)/2;
        int x = sqrt(cal);
        if(x*x == cal) return x;
        return -1;
    }
};