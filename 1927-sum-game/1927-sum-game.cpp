class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();

        int lefts=0, rights=0, qleft=0, qright=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?') qleft++;
            else lefts+=num[i]-'0';
        }

        for(int i=n/2;i<n;i++){
            if(num[i]=='?') qright++;
            else rights+=num[i]-'0';
        }

        if((qleft+qright)%2==1) return true;

        int sumdiff = lefts-rights;
        int qdiff = qright-qleft;
        return sumdiff*2 != qdiff*9;
    }
};