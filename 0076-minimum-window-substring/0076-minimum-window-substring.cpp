class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mpp(128,0);
        int cnt = t.length();
        int start=0;
        int end=0;
        int minlen = INT_MAX;
        int strtind = 0;

        for(char c: t){
            mpp[c]++;
        }

        while(end < s.length()){
            if(mpp[s[end++]]-- > 0){
                cnt--;
            }

            while(cnt==0){
                if(end - start <minlen){
                    strtind = start;
                    minlen = end-start;
                }

                if(mpp[s[start++]]++ == 0){
                    cnt++;
                }
            }
        }
        return minlen==INT_MAX ? "" : s.substr(strtind, minlen);
    }
};