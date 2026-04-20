class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int max_len=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(colors[i]!=colors[j]){
                    max_len = max(max_len, j-i);
                }
            }
        }
        return max_len;
    }
};