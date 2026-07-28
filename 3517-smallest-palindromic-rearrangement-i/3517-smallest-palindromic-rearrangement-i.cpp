class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> mpp;
        for(char c :s){
            mpp[c]++;
        }
        int cnt=0;
        char mid = '\0';
        string srt="";
        for(auto it: mpp){
            char ch = it.first;
            int ct=it.second;
            if(ct%2!=0){
                mid = ch;
                cnt++;
            }
            srt.append(ct/2,ch);

        }
        if(cnt>1) return "";
        string res= srt;
        reverse(res.begin(), res.end());
        if(mid!='\0'){
            return srt+mid+res;
        }
        return srt+res;
    }
};