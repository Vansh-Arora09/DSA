class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int  n = code.size();

        unordered_map<string,int> sort_order = {
            {"electronics",0},
            {"grocery",1},
            {"pharmacy",2},
            {"restaurant",3}
        };

        vector<pair<pair<int,string>,string>> ans;
        for(int i=0;i<n;i++){
            if(!isActive[i]) continue;
            if(sort_order.find(businessLine[i])==sort_order.end()) continue;

            if(code[i].empty()) continue;
            bool isvalid = true;
            for(char c : code[i]){
                if(!(isalnum(c) || c=='_')){
                    isvalid = false;
                    break;
                }
            }
            if(!isvalid) continue;

            int sort_id = sort_order[businessLine[i]];
            ans.push_back({{sort_id,code[i]},code[i]});
        }
        sort(ans.begin(),ans.end());

        vector<string> res;
        for(auto i : ans){
            res.push_back(i.second);
        }

        return res;
    }
};