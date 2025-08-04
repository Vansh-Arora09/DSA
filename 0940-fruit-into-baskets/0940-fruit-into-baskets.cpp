class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen=0;
        int start=0;
        unordered_map<int,int> mpp;
        for(int i=0;i<fruits.size();i++){
            mpp[fruits[i]]++;

            while(mpp.size()>2){
                mpp[fruits[start]]--;
                if(mpp[fruits[start]]==0){
                    mpp.erase(fruits[start]);
                }
                start++;
            }
            maxlen = max(maxlen,i - start+1);
        }
        return maxlen;


    }
};