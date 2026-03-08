class Solution {
public:
    bool isVowel(char c){
        if(tolower(c)=='a' || tolower(c)=='e' || tolower(c)=='i' || tolower(c)=='o' || tolower(c)=='u') return true;
        return false;
    }
    string reverseVowels(string s) {
        int n = s.length();
        int a=0,b=n-1;
        while(a<b){
            if(!isVowel(s[a])) a++;
            if(!isVowel(s[b])) b--;
            if(isVowel(s[a]) && isVowel(s[b])){
                swap(s[a],s[b]);
                a++,b--;
            }
            
        }
        return s;
    }
};