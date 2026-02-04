class Solution {
public:
    vector<string> ans;
    string curr="";
    unordered_map<char, string> mpp{
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    void gencomb(string digits, int idx){
        if(idx==digits.size()){
            ans.push_back(curr);
            return;
        }
        string possible = mpp[digits[idx]];

        for(char ch : possible){
            curr.push_back(ch);
            gencomb(digits,idx+1);
            curr.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        ans.clear();
        curr="";
        gencomb(digits,0);
        return ans;        
        
    }
};