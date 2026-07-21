class Solution {
public:
    string reversii(string &s, int i, int j){
        while(i<j){
            swap(s[i], s[j]);
            i++, j--;
        }
        return s;
        
    }
    string reverseWords(string s) {
        int start=0;
        int i=0;
        int n = s.length();
        while(start<n){
            while(i<n && s[i]!=' '){
                i++;
            }
            reversii(s, start, i-1);
            start = i+1;
            i = start;
        }
        return s;
    }
};