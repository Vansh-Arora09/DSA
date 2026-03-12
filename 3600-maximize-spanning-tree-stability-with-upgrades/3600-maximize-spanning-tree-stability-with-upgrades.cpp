struct Edge{
    int u, v, w, type;
};

class DSU{
    public:
    vector<int> parent;

    DSU(vector<int> &p){
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
        if(pu !=pv){
            parent[pu] = pv;
        }
    }
};
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        // the strategy is to first add all the weights with must = 1
        // if they form a cycle return -1
        // then add maximum possible score from remaining edges i.e., edges with must=0 
        // double the lowest k scores 
        // minimize the ans for the final maximum minimum score

        // HINT: -where this maximize minimize or minimize maximize concept is there, Binary Serach is the blind topic to apply

        int ans = -1;
        if(edges.size() < n-1){
            return -1;
        }

        vector<Edge> sorted;
        sorted.reserve(edges.size());

        for(auto &edge : edges){
            sorted.push_back({edge[0], edge[1], edge[2], edge[3]});  // u, v, strength, must
        }

        vector<Edge> must;
        vector<Edge> optional;

        for(auto &edge : sorted){
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

        sort(optional.begin(), optional.end(), [](Edge &a, Edge &b){
            return b.w < a.w;
        });

        int selected=0;
        int stability = 2e9;
        vector<int> initial(n);
        iota(initial.begin(), initial.end(), 0);
        DSU dsu(initial);

        for(auto &edge : must){
            if(dsu.find(edge.u) == dsu.find(edge.v) || selected == n-1){
                return -1;
            }

            dsu.join(edge.u, edge.v);
            selected++;
            stability = min(stability, edge.w);
        }

        int l = 0;
        int r = stability;

        while(l<r){
            int mid = l + ((r-l+1)>>1);

            DSU dsumid(dsu.parent);

            int slc = selected;
            int doublecnt=0;

            for(auto & edge : optional){
                if(dsumid.find(edge.u)==dsumid.find(edge.v)){
                    continue;
                }

                if(edge.w >=mid){
                    dsumid.join(edge.u, edge.v);
                    slc++;
                }

                else if(doublecnt<k && edge.w*2 >= mid){
                    doublecnt++;
                    dsumid.join(edge.u, edge.v);
                    slc++;
                }
                else{
                    break;
                }

                if(slc==n-1){
                    break;
                }
            }
            if(slc!=n-1){
                r  =mid-1;
            }
            else{
                ans = mid;
                l = mid;
            }
        }
        return ans;
    }
};