class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mpp;
        vector<int> c;
        for(int i=0;i<A.size();i++){
            mpp[A[i]]++;
            mpp[B[i]]++;
            int cnt=0;
            for(auto it : mpp){
                if(it.second>1) cnt++;
            }
            c.push_back(cnt);
        }
        return c;
    }
};