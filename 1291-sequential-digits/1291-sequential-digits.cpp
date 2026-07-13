class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        string s1 = to_string(low);
        string s2 = to_string(high);
        vector<int> ans;
        for(int i=s1.size();i<=s2.size();i++){
            for(int j=0;j<=9-i;j++){
                string n = s.substr(j,i);
                int num = stoi(n);
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};