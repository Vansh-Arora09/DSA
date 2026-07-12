class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> tmp = arr;
        sort(tmp.begin(), tmp.end());
        unordered_map<int, int> mpp;
        int n = arr.size();
        int rank=1;
        for(int i=0;i<n;i++){
            if(mpp.find(tmp[i])==mpp.end()){
                mpp[tmp[i]] = rank;
                rank++;
            }
        }
        for(int i=0;i<n;i++){
            arr[i] = mpp[arr[i]];
        }
        return arr; 
    }
};