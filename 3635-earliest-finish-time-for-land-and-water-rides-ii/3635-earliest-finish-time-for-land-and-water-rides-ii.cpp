class Solution {
public:
    int min(int a, int b){
        return a<b ? a:b;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int maxi = INT_MAX;

        int land_finish=INT_MAX;
        for(int i=0;i<n;i++){
            land_finish = min(land_finish, landStartTime[i]+landDuration[i]);
        }

        for(int j=0;j<m;j++){
            int start = max(land_finish,waterStartTime[j]);
            int finish = start + waterDuration[j];
            maxi = min(maxi, finish);
        }

        int water_finish = INT_MAX;
        for(int j=0;j<m;j++){
            water_finish = min(water_finish, waterStartTime[j]+waterDuration[j]);
        }

        for(int i=0;i<n;i++){
            int start = max(water_finish, landStartTime[i]);
            int finish = start + landDuration[i];
            maxi = min(maxi, finish);
        }
        return maxi;
    }
};