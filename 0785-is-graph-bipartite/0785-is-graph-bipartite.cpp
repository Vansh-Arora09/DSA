class Solution {
public:

    bool dfs(int node, vector<int>&color, vector<vector<int>>&graph){
        for(auto ch : graph[node]){
            if(color[ch]==-1){
                color[ch] = (color[node]==0 ? 1 : 0);
                if(dfs(ch, color, graph)==false) return false;
            }
            else{
                if( color[ch]==color[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i] = 0;
                if(dfs(i, color, graph)==false) return false;
            }
        }
        return true;
    }
};