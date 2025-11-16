class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()==1 || numRows==1 || s.size()<numRows) return s;

        vector<string> ans(min(numRows,(int)s.size()));
        bool down=false;
        int idx=0;
        for(int i=0;i<s.size();i++){
            ans[idx]+= s[i];
            if(idx==0 || idx==numRows-1){
                down=!down;
            }
            idx+=down? 1:-1;
        }
        string res="";
        for(int i=0;i<ans.size();i++){
            res+=ans[i];
        }
        return res;
    }
};