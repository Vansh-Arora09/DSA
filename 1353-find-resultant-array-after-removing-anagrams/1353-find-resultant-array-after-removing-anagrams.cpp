class Solution {
public:
    bool areAnagram(string a, string b){
        if(a.length()!=b.length()){
            return false;
        }
        map<int,int> mpp;
        for(int i=0;i<a.length();i++){
            mpp[a[i]]++;
        }
        for(int i=0;i<b.length();i++){
            mpp[b[i]]--;
        }
        for(auto it :mpp){
            if(it.second!=0) return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            if(areAnagram(words[i],words[i-1])){
                continue;
            }
            else{
                res.push_back(words[i]);
            }
        }
        return res;
    }
};