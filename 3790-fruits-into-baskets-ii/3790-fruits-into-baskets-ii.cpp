class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt=0;
        int n = fruits.size();
        for(int i=0;i<n;i++){
            int remain=1;
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j]){
                    baskets[j]=0;
                    remain=0;
                    break;
                }
            }
            cnt+=remain;
        }
        return cnt;
    }
};