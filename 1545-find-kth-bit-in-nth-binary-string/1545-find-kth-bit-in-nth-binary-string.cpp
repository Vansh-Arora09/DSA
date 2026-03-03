class Solution {
public:
    string invert(string s){
        string res="";
        for(char c : s){
            if(c=='0'){
                res+='1';
            }
            else{
                res+='0';
            }
        }
        return res;
    }

    string reverse(string s){
        string res="";
        for(int i=s.length()-1;i>=0;i--){
            res+=s[i];
        }
        return res;
    }
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        vector<string> arr(n,"");
        arr[0]+= "0";
        for(int i=1;i<n;i++){
            arr[i]+= arr[i-1] + "1" + reverse(invert(arr[i-1]));
        }
        return arr[n-1][k-1];
    }
};