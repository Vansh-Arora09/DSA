class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int a=1;a<n;a++){
            int b = n-a;
            if(non_zero(a) && non_zero(b)){
                return {a,b};
            }
        }
        return {0,0};
    }
    bool non_zero(int a){
        while(a>0){
            int rem = a%10;
            if(rem==0) return false;
            a/=10;
        }
        return true;
    }
};