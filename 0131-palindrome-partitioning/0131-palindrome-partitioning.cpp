class Solution {
public:

    bool palin(string &s,int left,int right){
        while(left<right){
            if(tolower(s[left])!=tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void substring(string &s,vector<string>&curr,vector<vector<string>>&ans,int index){
        
        if(index == s.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(palin(s,index,i)){
                curr.push_back(s.substr(index,i-index+1));
                
                substring(s,curr,ans,i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> ans;
        
        substring(s,curr,ans,0);
        return ans;
    }
};