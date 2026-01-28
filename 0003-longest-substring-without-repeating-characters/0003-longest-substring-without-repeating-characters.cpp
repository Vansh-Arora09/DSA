class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<int,int> mpp;
        int left=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            
            if(mpp.find(s[i])!=mpp.end()){
                left = max(left, mpp[s[i]]+1);
            }
            mpp[s[i]] = i;

            maxlen = max(maxlen, i-left+1);
        }
        return maxlen;
    }
};