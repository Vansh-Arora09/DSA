class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &it : invocations){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        queue<int> q;
        q.push(k);
        vector<bool> vis(n);
        vis[k]=true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto &neigh : adj[curr]){
                if(!vis[neigh]){
                    vis[neigh]=true;
                    q.push(neigh);
                }
            }
        }

        bool canrem=true;
        for(auto & it: invocations){
            int u = it[0];
            int v = it[1];
            if(!vis[u] && vis[v]){
                canrem=false;
                break;
            }
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            if(canrem){
                if(!vis[i]){
                    res.push_back(i);
                }
            }
            else{
                res.push_back(i);
            }
        }
        return res;
    }
};