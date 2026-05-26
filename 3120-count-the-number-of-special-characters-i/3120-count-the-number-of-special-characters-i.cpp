class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> st;
        for(char ch : word){
            st.insert(ch);
        }
        int cnt=0;
        for(char c = 'a';c<='z';c++){
            if(st.count(c) && st.count(c-'a'+'A')){
                cnt++;
            }
        }
        return cnt;
    }
};