class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string target = s+s;
        int cnt1=0, cnt2=0;
        int ans=n;
        for(int i=0;i<target.size();i++){
            if(target[i]-'0'!=(i%2)) cnt1++;
            if(target[i]-'0'!=(i+1)%2) cnt2++;

            if(i>=n){
                if(target[i-n]-'0'!=(i-n)%2) cnt1--;
                if(target[i-n]-'0'!=(i-n+1)%2) cnt2--;
            }

            if(i>=n-1){
                ans = min({ans,cnt1,cnt2});
            }
        }
        return ans;
    }
};