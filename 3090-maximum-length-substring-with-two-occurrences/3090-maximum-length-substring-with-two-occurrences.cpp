class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> cnt(26);
        int left=0;
        int res=0;
        int n = s.length();
        for(int right=0;right<n;right++){
            int ch = s[right]-'a';
            cnt[ch]++;
            while(cnt[ch]>2){
                const int ch2 = s[left]-'a';
                cnt[ch2]--;
                left++;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};