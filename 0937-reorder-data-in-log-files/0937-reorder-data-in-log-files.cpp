class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        map<string, priority_queue<string, vector<string>,greater<string>>> mpp;

        vector<string> v;

        for(string s : logs){
            string str = "";
            int i;
            for(i=0;s[i]!=' ';i++){
                str+=s[i];
            }

            if(isalpha(s[i+1])){
                mpp[s.substr(i+1)].push(str);
            }
            else{
                v.push_back(s);
            }
        }
        logs.clear();
        for(auto i : mpp){
            while(!i.second.empty()){
                logs.push_back(i.second.top() + ' '+ i.first);
                i.second.pop();
            }
        }
        logs.insert(logs.end(),v.begin(),v.end());
        return logs;
    }
};