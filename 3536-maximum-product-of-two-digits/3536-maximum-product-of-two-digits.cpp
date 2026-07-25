class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0;
        int sec=0;
        int tmp=n;
        while(tmp!=0){
            int rem = tmp%10;
            if(rem>=maxi){
                sec = maxi;
                maxi = rem;
            }
            else if(rem<maxi && rem>sec) sec = rem;
            tmp/=10;
        }
        return maxi*sec;
    }
};