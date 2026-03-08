class Solution {
public:
    string finalString(string s) {
        string st="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='i'){
                st+=s[i];
            }
            else{
                reverse(st.begin(),st.end());
            }
        }
        return st;
    }
};