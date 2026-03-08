class Solution {
public:
    string finalString(string s) {
        deque<char> d;
        int n = s.length();
        bool rev = false;
        for(int i=0;i<n;i++){
            if(s[i]=='i'){
                rev= !rev;
            }
            else{
                if(!rev){
                    d.push_back(s[i]);
                }
                else{
                    d.push_front(s[i]);
                }
            }
        }
        string st(d.begin(), d.end());
        if(rev){
            reverse(st.begin(), st.end());
        }
        return st;
    }
};