class Solution {
public:

    bool canposs(long long maxheig, int mounheig, vector<int>&worker){
        
        long long total=0;
        for(int w : worker){

            long long limit = 2 * maxheig/w;
            long long quad = (-1 + sqrt(1 + 4*limit))/2;

            total+= quad;

            if(total >= mounheig) return true;
        }

        return total>=mounheig;
        
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0;
        long long right = 1e16;
        long long ans = right;

        while(left<=right){
            long long mid = left + (right-left)/2;

            if(canposs(mid, mountainHeight, workerTimes)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};