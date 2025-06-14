class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string temp = s;
        string sec_tmp = temp;
        int n = temp.length();
        char max;
        char min;
        for(int i=0;i<n;i++){
            if(s[i]!='9'){
                max = s[i];
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]!='0'){
                min = s[i];
                break;
            }
        }
        for(int i=0;i<n;i++){
            temp[i] = s[i];
            if(s[i]==max){
                temp[i] = '9';
            }
            
        }
        for(int i=0;i<n;i++){
            sec_tmp[i]= s[i];
            if(s[i]==min){
                sec_tmp[i] = '0';
            }
        }
        return stoi(temp) - stoi(sec_tmp);
    }
};