class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        string res="";
        for(int i=0;i<n;i++){
            if(islower(s[i])){
                res.push_back(s[i]);
            }
            else if(s[i]=='*' && !res.empty()){
                res.pop_back();
            }
            else if(s[i]=='#'){
                int len = res.length();
                for(int j=0;j<len;j++){
                    res.push_back(res[j]);
                }
            }
            else{
                reverse(res.begin(),res.end());
            }
        }
        return res;
    }

};