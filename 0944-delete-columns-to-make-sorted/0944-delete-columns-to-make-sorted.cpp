class Solution {
public:
bool isort(vector<string>strs,int j){
    for(int i=1;i<strs.size();i++){
        if(strs[i][j]< strs[i-1][j]) return true;
    }
    return false;
}
    int minDeletionSize(vector<string>& strs) {
        int cnt=0;
        for(int i=0;i<strs[0].size();i++){
            cnt+= isort(strs,i);
        }
        return cnt;
    }
};