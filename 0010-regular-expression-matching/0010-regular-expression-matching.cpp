class Solution {
public:
    vector<vector<int>> dp;
    bool isMatched(string s, string p, int i, int j){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(j==p.length()){
            return i==s.length();
        }

        bool current = (i<s.length() && (s[i]==p[j] || p[j]=='.'));
        bool ans=0;

        if(j+1<p.length() && (p[j+1]=='*')){
            ans = isMatched(s,p,i,j+2) || (current && isMatched(s,p,i+1,j));
        }
        else{
            ans = (current && isMatched(s,p,i+1,j+1));
        }
        return dp[i][j] = ans ? 1 : 0;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        dp.assign(n+1, vector<int>(m+1,-1));
        return isMatched(s,p,0,0);
    }
};