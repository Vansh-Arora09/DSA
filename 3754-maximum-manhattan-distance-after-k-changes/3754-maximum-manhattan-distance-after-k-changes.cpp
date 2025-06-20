class Solution {
public:
    int maxDistance(string s, int k) {
        int N = s.length();
        int ans=0;
        int n=0,w=0,e=0,st=0;
        for(int i=0;i<N;i++){
            switch(s[i]){
                case 'N':
                    n++;
                    break;
                case 'S':
                    st++;
                    break;
                case 'E':
                    e++;
                    break;
                case 'W':
                    w++;
                    break;
            }
            int t1 = min({n,st,k});
            int t2 = min({e,w,k-t1});
            ans = max(ans,count(n,st,t1)+count(e,w,t2));
        }
        return ans;
    }
    int count(int d1,int d2,int times){
        return abs(d1-d2)+times*2;
    }
};