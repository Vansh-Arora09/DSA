class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi = *max_element(costs.begin(), costs.end());

        int n = costs.size();

        vector<int> count(maxi+1,0);

        for(int i: costs){
            count[i]++;
        }

        int arr_in = 0;
        for(int i=0;i<=maxi;i++){
            while(count[i]>0){
                costs[arr_in] = i;
                arr_in++;
                count[i]--;
            }
        }
        int cnt=0;
        for(int i: costs){
            if(i<=coins){
                cnt++;
                coins-=i;
            }
        }
        return cnt;
    }
};