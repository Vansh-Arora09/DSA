class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int,int> mpp;
        for(char c : text){
            mpp[c]++;
        }
        int mini = min({mpp['b'], mpp['a'], mpp['l']/2, mpp['o']/2, mpp['n']});
        return mini;
    }
};