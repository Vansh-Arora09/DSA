class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int m = 0;
        for(int c : nums){
            m = max(m,c);
        }
        int t=1;
        while(t<=m){
            t<<=1;
        }
        vector<int> one(t), two(t), three(t);
        for(int c : nums){
            one[c] =1;
            for(int i=0;i<t;i++){
                if(one[i]){
                    two[i^c] = 1;
                }
            }
        }
        for(int v : nums){
            for(int x=0;x<t;x++){
                if(two[x]){
                    three[x^v]=1;
                }
            }
        }
        int ans=0;
        for(int x=0;x<t;x++){
            if(three[x]){
                ans++;
            }
        }
        return ans;
    }
};