class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int,int> mpp;
        for(char ch : word){
            mpp[ch]++;
        }

        vector<int> frq;
        for(auto it : mpp){
            frq.push_back(it.second);
        }

        sort(frq.rbegin(), frq.rend());
        int push=0;
        for(int i=0;i<frq.size();i++){
            push+= (frq[i]*((i/8)+1));
        }
        return push;

        
    }
};