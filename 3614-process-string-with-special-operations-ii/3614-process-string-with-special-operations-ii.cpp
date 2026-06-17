class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();

        vector<long long> len(n,0);
        long long curr=0;
        for(int i=0;i<n;i++){
            if(islower(s[i])){
                curr++;
            }
            else if(s[i]=='*' && curr>0){
                curr--;
            }
            else if(s[i]=='#'){
                curr*=2;
            }
            len[i] = curr;
        }

        if(k>=curr) return '.';

        bool rev=false;
        for(int i=n-1;i>=0;i--){
            if(len[i]==0) continue;

            if(rev){
                k = len[i]-k-1;
                rev = false;
            }

            if(islower(s[i])){
                if(k==len[i]-1){
                    return s[i];
                }
            }

            else if(s[i]=='#'){
                long long half = len[i]/2;
                if(k>=half){
                    k%=half;
                }
            }
            else if(s[i]=='%'){
                rev = !rev;
            }
        }
        return '.';
    }
};