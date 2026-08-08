class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> last(m,-1);
        int p2 = m-1;
        for(int p1=n-1;p1>=0 && p2>=0 ;p1--){
            if(word1[p1]==word2[p2]){
                last[p2] = p1;
                p2--;
            }
        }
        vector<int> ans;
        bool changed=false;
        int i=0,j=0;
        while(i<n && j<m){
            bool match = (word1[i]==word2[j]);

            if(match){
                ans.push_back(i);
                i++,j++;
            }
            else{
                bool chang = !changed && (j==m-1 || last[j+1]>i);
                if(chang){
                    changed=true;
                    ans.push_back(i);
                    i++,j++;
                }
                else{
                    i++;
                }
            }
        }
        if(ans.size()==m) return ans;
        return {};

    }
};