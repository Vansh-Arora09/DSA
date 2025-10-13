class Solution {
public:
    bool isAnagram(string a, string b) {
        
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
};