class Solution {
public:
    vector<vector<int>> dp;
    bool Check(string &s, string &p, int i, int j){
        if(j==p.length()){
            //that means end of the string , no more checking in s ;
            return s.length()==i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        bool curr = (i<s.length() && (s[i]==p[j] || p[j]=='.'));
        int ans=0;
        if(j+1<p.length() && p[j+1]=='*'){
            ans = curr && Check(s,p,i+1,j) || Check(s,p,i,j+2);
        }
        else{
            ans = curr && Check(s,p,i+1,j+1);
        }
        return dp[i][j] = ans ? 1:0;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        dp.assign(n+1, vector<int>(m+1,-1));
        return Check(s,p,0,0);
    }
};