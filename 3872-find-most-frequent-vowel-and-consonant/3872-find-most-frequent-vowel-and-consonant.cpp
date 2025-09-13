class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxFreqSum(string s) {
        unordered_map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }
        int vow = 0;
        int cons=0;
        for(auto it: mpp){
            if(isVowel(it.first) && vow<it.second){
                vow  = it.second;
            }
            if(!isVowel(it.first) && cons<it.second){
                cons = it.second;
            }
        }
        return vow+cons;
    }
};