class Solution {
public:
    int min(int a, int b){
        return a<b ? a:b;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        long long maxi = 1e9;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int finishland = landStartTime[i]+landDuration[i];
                int startTime = max(finishland, waterStartTime[j]);
                int max1 = startTime + waterDuration[j];

                int finish = waterStartTime[j] + waterDuration[j];
                int start = max(finish,landStartTime[i]);
                int max2 = start + landDuration[i];

                maxi = min(maxi,min(max1,max2));
            }
        }
        return maxi;
    }
};