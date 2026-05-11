class Solution {
public:
    int alternateDigitSum(int n) {
        int digit;
        int sum=0;
        int temp = n;
        int count = 0;

        // Count digits to see if we need to start with + or -
        while (temp > 0) {
            temp /= 10;
            count++;
        }
        if(count%2==0) digit = -1;
        else digit = 1;
        while(n>0){
            int rem = n%10;
            sum+=(digit*rem);
            n/=10;
            digit = -(digit);
        }
        return sum;

    }
};