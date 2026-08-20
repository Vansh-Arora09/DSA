class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> mpp;
        for(int i=0;i<names.size();i++){
            mpp[heights[i]] = names[i];
        }

        sort(heights.begin(),heights.end());
        for(int i=0;i<names.size();i++){
            names[i] = mpp[heights[names.size()-i-1]];
        }
        return names;
    }
};