class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        const int mod = 1e9 + 7;
        unordered_map<float,vector<float>> slope;
        unordered_map<int,vector<float>> mid;
        int ans=0;

        for(int i=0;i<n;i++){
            int x1 = points[i][0];
            int y1  =points[i][1];
            for(int j=i+1;j<n;j++){
                int x2  =points[j][0];
                int y2 = points[j][1];
                int dx = x1-x2;
                int dy = y1-y2;

                float m,b;
                if(x2==x1){
                    m = mod;
                    b = x1;
                }
                else{
                    m = (float)(y2-y1)/(x2-x1);
                    b = (float)(y1*dx - x1*dy)/dx;
                }
                int middle = (x1+x2)*10000+(y1+y2);
                slope[m].push_back(b);
                mid[middle].push_back(m);
            }
        }
            for(auto [_,st] : slope){
                if(st.size()==1){
                    continue;
                }
                map<float,int>cnt;
                for(float b:st){
                    cnt[b]++;
                }

                int sum=0;
                for(auto [_,count]:cnt){
                    ans+=sum*count;
                    sum+=count;
                }
            }
            for(auto [_,mts]:mid){
                if(mts.size()==1){
                    continue;
                }
                map<float,int>cnt;
                for(float k:mts){
                    cnt[k]++;
                }
                int sum=0;
                for(auto [_,count]:cnt){
                    ans-=sum*count;
                    sum+=count;
                }
            }
        return ans;
    }
};