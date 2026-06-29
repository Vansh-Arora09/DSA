class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int cnt=0;
        for(string pat: patterns){
            if(pat.empty()) continue;
            if(word.find(pat)!= string :: npos) cnt++;
        }
        return cnt;
    }
};