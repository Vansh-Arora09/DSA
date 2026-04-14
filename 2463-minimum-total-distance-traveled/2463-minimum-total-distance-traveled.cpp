class Solution {
public:

    long long calc(int rid, int fid, vector<int> &robot, vector<int>&fact, vector<vector<long long>>&dp){
        if(rid==robot.size()) return 0;
        if(fid==fact.size()) return 1e12;
        if(dp[rid][fid]!=-1) return dp[rid][fid];

        long long assign = abs(robot[rid] - fact[fid]) + calc(rid+1, fid+1, robot, fact, dp);
        long long skip = calc(rid, fid+1, robot, fact, dp);

        return dp[rid][fid] = min(assign, skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(),factory.end());

        vector<int> fact;
        for(auto f: factory){
            for(int j=0;j<f[1];j++){
                fact.push_back(f[0]);
            }
        }

        int rcnt=robot.size(), fcnt = fact.size();

        vector<vector<long long>> dp(rcnt, vector<long long>(fcnt, -1));

        return calc(0,0, robot, fact, dp);
    }
};