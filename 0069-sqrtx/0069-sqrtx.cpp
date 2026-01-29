class Solution {
public:
    int mySqrt(int x) {
        long long start = 0;
        long long ans=0;
        long long end = x;
        while(start<=end){
            long long mid = (start+end)/2;
            if(mid*mid <= x){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};