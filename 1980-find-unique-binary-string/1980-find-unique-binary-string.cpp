class Solution {
public:
    int n;
    unordered_set<string> set;
    string generate(string curr){
        if(curr.length()==n){
            if(set.find(curr)!=set.end()){
                return "";
            }
            return curr;
        }
        string addzero = generate(curr+"0");
        if(addzero.size()>0){
            return addzero;
        }
        return generate(curr+"1");
    }
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        for(string s : nums){
            set.insert(s);
        }
        return generate("");
    }
};