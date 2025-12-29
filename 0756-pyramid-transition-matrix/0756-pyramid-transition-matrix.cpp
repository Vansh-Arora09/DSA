class Solution {
public:
    vector<int> all[7][7];
    unordered_set<string> vis;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(string s : allowed){
            int a = s[0]-'A';
            int b = s[1]-'A';
            int c = s[2]-'A';
            all[a][b].push_back(c);
        }
        return build(bottom);
    }
    bool build(string curr){
        if(curr.size()==1) return true;
        if(vis.count(curr)) return false;

        vis.insert(curr);
        return buildnext(curr, "",0);
    }

    bool buildnext(string row, string nextrow, int ind){
        if(ind==row.size()-1){
            return build(nextrow);
        }
        int left = row[ind]-'A';
        int right = row[ind+1]-'A';

        for(int par : all[left][right]){
            if(buildnext(row, nextrow+ char(par+'A'), ind+1)){
                return true;
            }
        }
        return false;
    }
};