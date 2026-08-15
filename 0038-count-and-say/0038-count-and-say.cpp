class Solution {
public:
    string cnt(int n){
        if(n==1) return "1";
        string previous = cnt(n-1);
        string res="";
        int ct=1;
        for(int i=0;i<previous.size();i++){
            if(i==previous.size()-1 || previous[i]!=previous[i+1]){
                res+=to_string(ct);
                res+=previous[i];
                ct=1;
            }
            else{
                ct++;
            }
        }
        return res;
    }

    string countAndSay(int n) {
        return cnt(n);
    }
};