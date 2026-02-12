class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        vector<int> ch(26);
        int res=0;
        for(int i=0;i<n;i++){
            fill(ch.begin(),ch.end(),0);
            for(int j=i;j<n;j++){
                bool flag = true;
                int c = s[j]-'a';
                ch[c]++;
                for(auto x :ch){
                    if(x>0 && x!=ch[c]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    res = max(res,j-i+1);
                }
            }
        }
        return res;
    }
};