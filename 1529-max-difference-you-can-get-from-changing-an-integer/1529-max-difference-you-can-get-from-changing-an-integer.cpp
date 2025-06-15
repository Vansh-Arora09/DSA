class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.length();
        string maxstr = s;
        string minstr = s;
        char maxi = '0';
        char mini = '0';
        if(s[0]=='9'){
            for(int i=1;i<n;i++){
                if(s[i]!='9'){
                    maxi = s[i];
                    break;
                }
            }
        }
        else{
            maxi = s[0];
        }

        if(s[0]=='1'){
            for(int i=1;i<n;i++){
                if(s[i]!='0' && s[i]!='1'){
                    mini = s[i];
                    break;
                }
            }
        }
        else{
            mini = s[0];
        }

        for(int i=0;i<n;i++){
            if(s[i]==maxi){
                maxstr[i] = '9';
            }
        }
        if(s[0]=='1'){
            for(int i=1;i<n;i++){
                if(s[i]==mini){
                    minstr[i] = '0';
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(s[i]==mini){
                    minstr[i] = '1';
                }
            }
        }
        return stoi(maxstr) - stoi(minstr);
    }
};