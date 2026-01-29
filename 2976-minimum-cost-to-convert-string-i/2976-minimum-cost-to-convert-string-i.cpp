class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
       
        const long long INF = 1e15; 
        vector<vector<long long>> min_cost(26, vector<long long>(26, INF));

        for (int i = 0; i < 26; ++i) min_cost[i][i] = 0;

        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            min_cost[u][v] = min(min_cost[u][v], (long long)cost[i]);
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    min_cost[i][j] = min(min_cost[i][j], min_cost[i][k] + min_cost[k][j]);
                }
            }
        }

        long long totalCost = 0;
        for (int i = 0; i < source.length(); ++i) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            
            if (min_cost[s][t] >= INF) return -1;
            totalCost += min_cost[s][t];
        }

        return totalCost;
    }
};