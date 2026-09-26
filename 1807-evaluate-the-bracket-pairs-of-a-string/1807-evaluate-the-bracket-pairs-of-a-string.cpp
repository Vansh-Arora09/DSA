class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for(auto it : knowledge){
            mpp[it[0]] = it[1];
        }

        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                int j=i+1;
                string tmp="";
                while(s[j]!=')'){
                    tmp+=s[j];
                    j++;
                }
                i = j;
                if(mpp.find(tmp)!=mpp.end()){
                    for(char ch : mpp[tmp]) ans+=ch;
                }
                else{
                    ans+='?';
                }
            }
            else{
                ans+=s[i];
            }
        }

        return ans;
    }
};