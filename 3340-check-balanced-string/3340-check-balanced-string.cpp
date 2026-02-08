class Solution {
public:
    bool isBalanced(string num) {
        int n = num.length();
        int evn=0;
        int odd=0;
        for(int i=0;i<n;i+=2){
            odd+=(num[i]-'0');
        }
        for(int i=1;i<n;i+=2){
            evn+=(num[i]-'0');
        }
        if(evn==odd)return true;
        return false;
    }
};