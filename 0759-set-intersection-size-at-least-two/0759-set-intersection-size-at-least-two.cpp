class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto&a , auto&b){
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]>b[1];
        });

        int n = intervals.size();
        vector<int> res(n,2);
        int ans=0;
        for(int i = n-1;i>=0;i--){
            int s = intervals[i][0];
            int e = intervals[i][1];
            int m = res[i];

            for(int j = s;j<s+m;j++){
                for(int k=0;k<=i;k++){
                    if(res[k]>0 && j<=intervals[k][1]){
                        res[k]--;
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};