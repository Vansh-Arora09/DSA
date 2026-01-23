class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
    
        for(string x : strs){
            string word = x;
            vector<int> freq(26,0);
            for(char c : word){
                freq[c-'a']++;
            }
            string key = "";
            for (int j=0;j<26;j++){
                key+= string(freq[j], j+'a');
            }
            mpp[key].push_back(x);
        }

        vector<vector<string>> ans;
        for(auto x : mpp){
            ans.push_back(x.second);
        }
        return ans;
    }
};