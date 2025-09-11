class Solution {
public:
    bool isVowel(char s){
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u' || s=='A' || s=='E' || s=='I' || s=='O' || s=='U') return true;
        return false;
    }
    string sortVowels(string s) {
        int n = s.size();
        vector<char> temp;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])) temp.push_back(s[i]);
        }
        sort(temp.begin(),temp.end());
        int k=0;
        string str = "";
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                str.push_back(temp[k++]);
            }
            else{
                str.push_back(s[i]);
            }
        }
        return str;
    }
};