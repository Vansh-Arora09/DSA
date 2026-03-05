class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int one_strt = 1;
        int cnt1=0, cnt2=0;
        for(int i=0;i<n;i++){
            if(s[i]-'0'!=one_strt) cnt1++;
            one_strt = !one_strt;
        }
        int zero_strt = 0;
        for(int i=0;i<n;i++){
            if(s[i]-'0'!=zero_strt) cnt2++;
            zero_strt = !zero_strt;
        }
        return min(cnt1, cnt2);

    }
};