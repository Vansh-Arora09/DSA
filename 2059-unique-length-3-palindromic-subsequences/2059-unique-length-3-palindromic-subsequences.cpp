class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<int> letter;
        for(char ch:s){
            letter.insert(ch);
        }

        int ans=0;
        for(char ch : letter){
            int i=-1;
            int j= 0;
            for(int k=0;k<s.size();k++){
                if(s[k]==ch){
                    if(i==-1){
                        i=k;
                    }
                    j=k;
                }
            }

            unordered_set<char> between;
            for(int k=i+1;k<j;k++){
                between.insert(s[k]);
            }
            ans+=between.size();
        }
        return ans;
    }
};