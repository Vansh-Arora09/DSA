class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if(cost.size()<=2) return accumulate(cost.begin(),cost.end(),0);
        int ans=0;
        int cnt=0;
        sort(cost.begin(),cost.end(),greater<int>());
        for(int i=0;i<cost.size();i++){
            if(cnt==2){
                cnt=0;
                continue;
            }
            ans+=cost[i];
            cnt++;
        }
        return ans;
    }
};