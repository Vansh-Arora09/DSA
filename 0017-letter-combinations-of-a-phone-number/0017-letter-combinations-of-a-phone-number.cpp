class Solution {
public:
    vector<string> ans;
    string curr="";
    unordered_map<char, string> mpp{
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8',"tuv"},{'9', "wxyz"}
    };
    void Comb(string &digits, int i){
        if(i==digits.size()){
            ans.push_back(curr);
            return ;
        }
        string valid = mpp[digits[i]];
        for(char c : valid){
            curr.push_back(c);
            Comb(digits,i+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        Comb(digits,0);
        return ans;
    }
};