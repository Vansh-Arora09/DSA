class Solution {
public:

    void dfs(int node, stack<int>&st, vector<int>&vis, vector<int> adj[]){
        vis[node] = true;
        for(auto ch : adj[node]){
            if(!vis[ch]){
                dfs(ch, st, vis, adj);
            }
        }
        st.push(node);
    }

    void dfs2(int node, vector<int>&scc, int cnt, vector<int>&vis, vector<int> adjT[] ){
        vis[node] = true;
        scc[node] = cnt;

        for(auto neigh : adjT[node]){
            if(!vis[neigh]){
                dfs2(neigh, scc, cnt, vis, adjT);
            }
        }
    }
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        //1. find first and last index of every character

        vector<int> first(26,-1), last(26,-1);

        for(int i=0;i<n;i++){
            if(first[s[i]-'a']==-1){
                first[s[i]-'a'] = i;
            }
            last[s[i]-'a'] = i;
        }

        //2. build the adjacency vector

        vector<int> adj[26];
        vector<bool> exists(26,false);

        for(int i=0;i<26;i++){
            if(first[i]==-1) continue;

            exists[i] = true;
            for(int j = first[i];j<=last[i];j++){
                if(s[j]-'a'!=i){
                    adj[i].push_back(s[j]-'a');
                }
            }
        }

        //3. dfs1 + stack
        stack<int> st;
        vector<int> vis(26,0);

        for(int i=0;i<26;i++){
            if(exists[i] && !vis[i]){
                dfs(i, st, vis, adj);
            }
        }

        //4. dfs2 + adjT

        vector<int> adjT[26];
        for(int i=0;i<26;i++){
            vis[i]=0;
            for(int neigh : adj[i]){
                adjT[neigh].push_back(i);
            }
        }

        vector<int> scc(26,-1);
        int cnt=0;
        while(!st.empty()){
            int node = st.top(); st.pop();

            if(!vis[node]){
                dfs2(node, scc, cnt++, vis, adjT);
            }
        }
        //5. out_degree vector
        vector<int> out_deg(cnt,0);
        for(int i=0;i<26;i++){
            if(!exists[i]) continue;

            for(int neigh : adj[i]){
                if(scc[i]!=scc[neigh]){
                    out_deg[scc[i]]++;
                }
            }
        }

        vector<string> res;

        for(int i=cnt-1;i>=0;i--){
            if(out_deg[i]==0){
                //6. checking for left and rightmost index of a valid range
                int left = n;
                int right = -1;

                for(int idx=0;idx<26;idx++){
                    if(scc[idx]==i){
                        left = min(left, first[idx]);
                        right = max(right, last[idx]);
                    }
                }

                bool valid = true;

                for(int k=left;k<=right;k++){
                    if(scc[s[k]-'a']!=i){
                        valid  = false;
                        break;
                    }
                }
                // add substring to res
                if(valid){
                    res.push_back(s.substr(left, right-left+1));
                }
            }
        }
        return res;
    }
};