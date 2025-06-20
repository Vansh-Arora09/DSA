class Solution {
public:
    int maxDistance(string s, int k) {
        int N = s.length();
        int ans=0;
        int lat = 0, lon = 0;;
        for(int i=0;i<N;i++){
            switch(s[i]){
                case 'N':
                    lat++;
                    break;
                case 'S':
                    lat--;
                    break;
                case 'E':
                    lon++;
                    break;
                case 'W':
                    lon--;
                    break;
            }
            ans = max(ans,min(abs(lat)+abs(lon)+k*2,i+1));
        }
        return ans;
    }
};