class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()==1 || s.size()<=numRows || numRows==1) return s;

        string ans="";
        int l = (numRows-2)*2+2;
        int m = l;
        int n=0;
        int c=0;
        for(int i=0;i<numRows;i++){
            c=i;
            ans+=s[i];
            while(c<s.size() && n+m<=l){
                c+=m;
                if(c<s.size() && m!=0) ans+=s[c];
                c+=n;
                if(c<s.size() && n!=0) ans+=s[c];
            }
            m-=2;
            n+=2;
        }
        return ans;
    }
};