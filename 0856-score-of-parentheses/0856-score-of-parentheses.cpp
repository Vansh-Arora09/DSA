class Solution {
public:
    int scoreOfParentheses(string s) {
        int sc=0, dep=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') dep++;
            else if(s[i]==')') dep--;
            if(i>0 && (s[i-1]=='(' && s[i]==')')) sc+=1<<dep;
        }
        return sc;
    }
};