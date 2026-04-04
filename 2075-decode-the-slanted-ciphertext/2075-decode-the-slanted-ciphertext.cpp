class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();

        if(rows==1) return encodedText;
        if(rows==0) return "";

        int cols = n/rows;
        string res="";
        for(int c=0;c<cols;c++){
            for(int r=0,j=c;r<rows && j<cols;r++,j++){
                res+= encodedText[r*cols + j];
            }
        }
        while(!res.empty() && res.back()==' ') res.pop_back();
        return res;
    }

};