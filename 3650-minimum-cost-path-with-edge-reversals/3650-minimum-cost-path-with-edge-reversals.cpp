class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }

        vector<int> d(n,INT_MAX);
        vector<bool> vis(n,false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        d[0]=0;
        q.emplace(0,0);

        while(!q.empty()){
            int top = q.top().second;
            q.pop();

            if(top==n-1) return d[top];

            if(vis[top]) continue;
            vis[top] = 1;

            for(auto [y,w]: adj[top]){
                if(d[top]+w<d[y]){
                    d[y] = d[top] + w;
                    q.emplace(d[y],y);
                }
            }
        }
        return -1;
    }
};