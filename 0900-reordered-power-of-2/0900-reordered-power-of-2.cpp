class Solution {
public:

    vector<int> digitfreq(int n){
        vector<int> freq(10,0);
        while(n>0){
            freq[n%10]++;
            n/=10;
        }
        return freq;
    }

    bool equalFreq(const vector<int>&a, const vector<int>&b){
        for(int i=0;i<10;i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> target = digitfreq(n);

        for(int i=0;i<=30;i++){
            int pwr = (int)pow(2,i);
            if(equalFreq(target,digitfreq(pwr))){
                return true;
            }
        }
        return false;
    }
};