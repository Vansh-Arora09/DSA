class Solution {
public:

    void rev(vector<char>&s , int i, int j){
        if(i>=j){
            return;
        }

        char ch = s[i];
        s[i] = s[j];
        s[j]= ch;
        rev(s, i+1, j-1);
    }
    void reverseString(vector<char>& s) {
        // not using any loop or STL function

        rev(s, 0, s.size()-1);
    }
};