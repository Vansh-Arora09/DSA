class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt=0;
        for(int i=100;i<=999;i++){
            if(i%2==0){
                int c = i%10;
                int b = (i/10)%10;
                int a = i/100;
                vector<int> freq(10,0);
                for(int i : digits){
                    freq[i]++;
                }
                freq[c]--;
                freq[b]--;
                freq[a]--;

                if(freq[c]>=0 && freq[b]>=0 && freq[a]>=0) cnt++;
            }
        }
        return cnt;
    }
};