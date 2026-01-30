class Solution {
public:
    bool canSend(vector<int>&weights, int maxWeight, int days){
        int n = weights.size();
        int currWeight = 0;
        int daytaken = 0;
        for(int i=0;i<n;i++){
            if(currWeight + weights[i] > maxWeight){
                daytaken++;
                currWeight = weights[i];
            }
            else{
                currWeight+= weights[i];
            }
        }
        daytaken++; // to ship last shipment
        return daytaken<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        while(start<=end){
            int mid = start+(end-start)/2;

            if(canSend(weights, mid, days)){
                ans = mid; // either store like this or return end+1 directly
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};