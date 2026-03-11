class Solution {
public:
    string tobin(int n){
        if(n==0) return "1";
        string s="";
        while(n>0){
            int rem = n%2;
            if(rem==0) s+='1';
            else s+='0';
            n/=2;
        }
        return s;
    }
    int to_dec(string s){
        int sum=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                sum+= pow(2,i);
            }
        }
        return sum;
    }
    int bitwiseComplement(int n) {
        string s = tobin(n);
        int ans = to_dec(s);
        return ans;
    }
};