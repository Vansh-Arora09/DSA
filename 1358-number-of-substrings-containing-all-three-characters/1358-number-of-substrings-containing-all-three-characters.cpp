class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> lastpos = {-1,-1,-1};
        int total=0;

        for(int i=0;i<n;i++){
            lastpos[s[i]-'a'] = i;

            total+= 1 + min({lastpos[0], lastpos[1], lastpos[2]});
        }
        return total;
    }
};