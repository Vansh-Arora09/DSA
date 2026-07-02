class Solution {
public:
    string getPermutation(int n, int k) {
        string a = "";
        for(int i=1;i<=n;i++){
            a.push_back((i+'0'));
        }
        for(int i=0;i<k-1;i++){
            next_permutation(a.begin(), a.end());
        }

        return a;
    }
};