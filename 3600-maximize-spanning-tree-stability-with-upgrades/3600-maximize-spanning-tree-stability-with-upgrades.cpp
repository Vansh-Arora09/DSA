
struct Edge{
    int u, v, w, type;
};

class DSU{
    public:
    vector<int> parent;

    DSU(vector<int>&p){
        parent = p;
    }

    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void join(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu!=pv){
            parent[pu] = pv;
        }
    }
};
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        
        
        //do it agin for practice and to understand the concept of dsu and graph 
        int ans = -1;

        if(edges.size() < n-1){
            return -1;
        }

        vector<Edge> sorted;
        sorted.reserve(edges.size());
        for(auto &edge : edges){
            sorted.push_back({edge[0],edge[1],edge[2],edge[3]});
        }

        vector<Edge> must;
        vector<Edge> optional;
        for(auto & edge : sorted){
            if(edge.type==1){
                must.push_back(edge);
            }
            else{
                optional.push_back(edge);
            }
        }
        if(must.size() > n-1){
            return -1;
        }

        sort(optional.begin(),optional.end(),[](Edge &a, Edge &b){
            return a.w > b.w;
        });

        int cnt=0;
        int stability = 2e9;
        vector<int> initial(n);
        iota(initial.begin(), initial.end(),0);
        DSU dsu(initial);
        
        for(auto &edge : must){
            if(dsu.find(edge.u)==dsu.find(edge.v)){
                return -1;
            }
            dsu.join(edge.u, edge.v);
            cnt++;
            stability = min(stability, edge.w);
        }

        int l=0;
        int r=stability;

        while(l<r){
            int mid = l + ((r-l+1)/2);
            DSU dsu2(dsu.parent);
            int doublecnt=0;
            int slc = cnt;

            for(auto &edge : optional){
                if(dsu2.find(edge.u)==dsu2.find(edge.v)){
                    continue;
                }

                if(edge.w>=mid){
                    dsu2.join(edge.u, edge.v);
                    slc++;
                }
                else if(doublecnt < k && edge.w*2 >=mid){
                    dsu2.join(edge.u, edge.v);
                    doublecnt++;
                    slc++;
                }
                
                if(slc==n-1){
                    break;
                }
            }
            if(slc!=n-1){
                r = mid-1;
            }
            else{
                ans = mid;
                l = mid;
            }
        }
        
        return ans;
    }
};