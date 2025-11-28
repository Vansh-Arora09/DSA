class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> ajlist(n);
        for(auto edg: edges){
            int node1 =edg[0];
            int node2 = edg[1];
            ajlist[node1].push_back(node2);
            ajlist[node2].push_back(node1);
        }

        int count=0;
        dfs(0,-1,ajlist,values,k,count);
        return count;
    }

    private:
        int dfs(int curr, int par, vector<vector<int>> &ajlist,vector<int>&values,int k, int &count){
            int sum=0;
            for(auto neigh:ajlist[curr]){
                if(neigh!=par){
                    sum+= dfs(neigh,curr,ajlist,values,k,count);
                    sum%=k;
                }
            }

            sum+= values[curr];

            sum%=k;
            if(sum==0) count++;
            return sum;
        }
};