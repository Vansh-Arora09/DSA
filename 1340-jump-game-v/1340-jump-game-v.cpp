class Solution {
public:
    vector<int> ans;

    void dfs(vector<int>& arr, int id, int d, int n){
        if(ans[id]!=-1) return;

        ans[id] = 1;
        for(int i=id-1;i>=0 && id-i<=d && arr[id]>arr[i];i--){
            dfs(arr,i,d,n);
            ans[id] = max(ans[id],ans[i]+1);
        }
        for(int i=id+1;i<n && i-id<=d && arr[id]>arr[i];i++){
            dfs(arr,i,d,n);
            ans[id] = max(ans[id],ans[i]+1);
        }
    }
    int maxJumps(vector<int>& arr, int d) {
        int n =arr.size();
        ans.resize(n,-1);
        for(int i=0;i<n;i++){
            dfs(arr,i,d,n);
        }
        return *max_element(ans.begin(), ans.end());
    }
};