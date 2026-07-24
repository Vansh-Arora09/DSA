class Solution {
public:
    void rev(string& s, int i, int j){
        while(i<=j){
            swap(s[i], s[j]);
            i++,j--;
        }
    }
    string reverseWords(string s) {
        int n = s.length();
        int srt=0, i=0;
        while(srt<n){
            while(i<n && s[i]!=' '){
                i++;
            }
            rev(s, srt,i-1);
            srt = i+1;
            i = srt;
        }
        return s;
    }
};