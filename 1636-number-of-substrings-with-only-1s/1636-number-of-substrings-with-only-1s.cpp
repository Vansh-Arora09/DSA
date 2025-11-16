class Solution {
public:
    int numSub(string s) {
        int n = s.length();
        const long long MOD = 1e9+7;
        long long ans=0;
        for(int i=0;i<n;i++){
            long long cnt=0;
            if(s[i]=='1'){
                while(i<n && s[i]=='1'){
                    cnt++;
                    i++;
                }
                ans=(ans+(((cnt+1)*cnt)/2))%MOD;
            }
        }
        return ans;
    }
};