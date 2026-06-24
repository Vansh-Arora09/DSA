class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<int,int> mpp;
        for(char c : stones){
            mpp[c]++;
        }
        int cnt=0;
        for(int i=0;i<jewels.size();i++){
            if(mpp[jewels[i]]) cnt+=mpp[jewels[i]];
        }
        return cnt;
        
    }
};