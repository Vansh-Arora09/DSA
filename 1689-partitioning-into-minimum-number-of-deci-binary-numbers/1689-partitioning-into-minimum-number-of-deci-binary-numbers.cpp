class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
        for(char c : n){
            if(c-'0' > maxi){
                maxi = (c-'0');
            }
        }
        return maxi;
    }
};