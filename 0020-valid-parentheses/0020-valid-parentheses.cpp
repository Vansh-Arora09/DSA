class Solution {
public:
    bool isValid(string k) {
        int n = k.length();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(k[i]=='(' || k[i]=='{' || k[i]=='['){
                st.push(k[i]);
            }
            else{
                if(st.empty() || 
                !((st.top()=='(' && k[i]==')') ||
                (st.top()=='{' && k[i]=='}') ||
                (st.top()=='[' && k[i]==']'))
                ){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};