class Solution {
public:
    vector<int> dp;
    bool ispalin(string &s, int i,  int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int mcuts(string &s, int i, int j){
        if(i==j || ispalin(s,i,j)) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = 1e9;
        for(int k=i;k<j;k++){

            if(ispalin(s,i,k)){
                int cost2 = mcuts(s,k+1,j);
                ans = min(ans, 1 + (cost2));
            }
        }

        return dp[i] = ans;
    }
    int minCut(string s) {
        dp.resize(s.length(),-1);
        return mcuts(s,0,s.length()-1);
    }
};