class Solution {
public:
    bool canIEat(vector<int>&piles, int speed, int h){
        long long  time = 0;
        for(int i=0;i<piles.size();i++){
            time+= (long long)((piles[i] + speed-1)/speed);
        }
        return (time<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int maxi = *max_element(piles.begin(), piles.end());
        int ans=0;
        while(start<=maxi){
            int mid = (start +maxi)/2;
            if(canIEat(piles, mid, h)){
                ans = mid;
                maxi = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};