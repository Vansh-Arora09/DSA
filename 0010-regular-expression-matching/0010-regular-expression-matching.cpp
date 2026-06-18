class Solution {
public:
    vector<vector<int>> dp;
    bool dfs(string s, string p, int i , int j){
        if(j==p.length()){
            return i==s.length();
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool curr = (i<s.length() && (s[i]==p[j] || p[j]=='.'));
        bool ans=false;

        if( j+1<p.length() && p[j+1]=='*'){
            ans = dfs(s,p,i,j+2) || (curr && dfs(s,p,i+1,j));
        }
        else{
            ans = curr && dfs(s,p,i+1,j+1);
        }
        return dp[i][j] = ans ? 1:0;
    }
    bool isMatch(string s, string p) {
        dp.assign(s.length()+1, vector<int>(p.length()+1, -1));

        return dfs (s,p,0,0);
    }
};