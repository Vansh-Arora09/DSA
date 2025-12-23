class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end());
        int ans=0;
        vector<int> suff(n);
        suff[n-1] = events[n-1][2];
        for(int i=n-2;i>=0;i--){
            suff[i] = max(suff[i+1],events[i][2]);
        }

        for(int i=0;i<n;i++){
            ans = max(ans, events[i][2]);

            int lo = i+1,hi = n-1, idx=-1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(events[mid][0]>events[i][1]){
                    idx = mid;
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            if(idx!=-1){
                ans = max(ans, events[i][2] + suff[idx]);
            }
        }
        return ans;
    }
};