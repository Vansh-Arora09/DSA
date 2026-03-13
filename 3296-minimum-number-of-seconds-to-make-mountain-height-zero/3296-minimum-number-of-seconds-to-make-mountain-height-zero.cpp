class Solution {
public:
    long long getmax(int w, long long limit){
        long long low = 0;
        long long high = 1e6;
        long long units=0;

        while(low<=high){
            long long x = low + (high-low)/2;

            if(w*(x*(x+1))/2 > limit){
                high = x-1;
            }
            else{
                units=x;
                low = x+1;
            }
        }
        return units;
    }
    bool canposs(long long maxheig, int mounheig, vector<int>&worker){
        
        long long total=0;
        for(int w : worker){
            total+= getmax(w, maxheig);

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