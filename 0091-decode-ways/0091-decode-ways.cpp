class Solution {
public:

    int recfun(string &s, int i, vector<int>&dp){
        if(i== s.length()) return 1;

        if(dp[i]!=-1) return dp[i];

        int single=0;
        if(s[i]!='0'){
            single = recfun(s,i+1, dp);
        }
        int dbl = 0;
        if(i<s.length()-1){
            string num = "";
            num+=s[i];
            num+=s[i+1];
            if(num>="10" && num<="26") dbl = recfun(s,i+2, dp);
        }
        return dp[i] = single + dbl;
        
    }
    int numDecodings(string s) {
        vector<int> dp(s.length(),-1);
        return recfun(s, 0, dp);
    }
};