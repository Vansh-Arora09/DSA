class Solution {
public:
    const vector<string> below20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    const vector<string> below100 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    const vector<string> uptoBill = {"", "Thousand", "Million", "Billion"};

    string helper(int num){
        if(num==0) return "";
        if(num<20) return below20[num]+" ";
        else if(num<100) return below100[num/10] + " " + helper(num%10);
        else{
            return below20[num/100] + " Hundred " + helper(num%100);
        }
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string result="";
        int chunkid=0;
        while(num>0){
            int chunk = num%1000;

            if(chunk!=0){
                result = helper(chunk) + uptoBill[chunkid] + " "+ result;
            }

            num/=1000;
            chunkid++;
        }

        while(!result.empty() && result.back()==' '){
            result.pop_back();
        }

        return result;



        
    }
};