class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> grph(n);

        unordered_map<string, int> mpp;
        for(int i=0;i<n;i++){
            grph[i].push_back(i);   // self loops;
        }

        for(auto &edge : edges){
            grph[edge[0]].push_back(edge[1]);
            grph[edge[1]].push_back(edge[0]);
        }

        for(int i=0;i<n;i++){
            vector<int> neigh = grph[i];
            sort(neigh.begin(), neigh.end());

            string k;
            for(int num : neigh){
                k+= to_string(num)+",";
            }
            mpp[k]++;
        }

        int cnt=0;
        for(auto& it : mpp){
            int size = count(it.first.begin(), it.first.end(), ',');
            if(size==it.second){
                cnt++;
            }
        }

        return cnt;
    }
};