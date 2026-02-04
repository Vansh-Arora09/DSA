class Solution {
public:
    string temp="";
    vector<string> ans;
    void genpar(int n, int openc, int closedc){
        if(n==openc && openc==closedc) {
            ans.push_back(temp);
            return;
        }
        if(openc<n){
            temp.push_back('(');
            genpar(n,openc+1,closedc);
            temp.pop_back();

        }

        if(closedc<openc){
            temp.push_back(')');
            genpar(n,openc, closedc+1);
            temp.pop_back();
        }
        
        
        
    }
    vector<string> generateParenthesis(int n) {       
        genpar(n,0,0);
        return ans;

    }
};