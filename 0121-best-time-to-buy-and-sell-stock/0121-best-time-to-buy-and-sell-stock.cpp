class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minm = prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            minm = min(minm, prices[i]);
            int profit = prices[i]-minm;
            ans = max(ans, profit);
        }
        return ans;
    }
};