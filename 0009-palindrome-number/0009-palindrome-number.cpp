class Solution {
public:
    bool isPalindrome(int x) {
        long long tmp=x;
        long long rev=0;
        while(tmp>0){
            int rem=tmp%10;
            rev = (rev*10)+rem;
            tmp/=10;
        }
        return rev==x;

    }
};