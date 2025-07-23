class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit= 0;
        int n = prices.size();
        int curr = prices[0];
        for(int i=1;i<n;i++){
            int amount = prices[i] - curr;
            profit = max(profit,amount);
            curr = min(curr, prices[i]);
        }
        return profit;
    }
};