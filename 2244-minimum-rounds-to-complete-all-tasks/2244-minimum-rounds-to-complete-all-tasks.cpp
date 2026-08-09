class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mpp;
        for(int t : tasks){
            mpp[t]++;
        }
        int total=0;
        for(auto [fst,sec] : mpp){
            if(sec==1) return -1;

            total+=((sec+2)/3);
        }
        return total;
    }
};