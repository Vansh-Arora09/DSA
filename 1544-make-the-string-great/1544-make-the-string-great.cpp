class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(!st.empty() && ( tolower(st.top()) == tolower(s[i]) && st.top()!=s[i])){
                st.pop();
                //i++;
            }
            else st.push(s[i]);
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};