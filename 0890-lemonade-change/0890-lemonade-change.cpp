class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int cnt_five = 0;
        int cnt_ten = 0;
        int cnt_twen = 0;
        for(int i=0;i<n;i++){
            if(bills[i]==5) cnt_five++;
            else if(bills[i]==10){
                cnt_ten++;
                if(cnt_five) cnt_five--;
                else return false;
            }
            else{ 
                cnt_twen++;
                if(cnt_ten>0 && cnt_five>0){
                    cnt_five--;
                    cnt_ten--;
                }
                else if(cnt_five>=3) cnt_five-=3;
                else{
                    return false;
                }
            }
        }
        
        return true;
    }
};