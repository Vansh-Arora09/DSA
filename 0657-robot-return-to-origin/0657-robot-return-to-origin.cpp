class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> mpp;
        for(int i=0;i<moves.length();i++){
            mpp[moves[i]]++;
        }

        if(mpp['L']==mpp['R'] && mpp['U']==mpp['D']) return true;
        return false;
    }
};