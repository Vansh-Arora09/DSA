class Solution {
public:
    void generate(int n, string curr, vector<string>& happy){
        if(curr.size()==n){
            happy.push_back(curr);
            return ;
        }

        for(char c = 'a';c<='c';c++){
            if(curr.size()>0 && curr.back()==c){
                continue;
            }

            generate(n, curr + c, happy);
        }
    }
    string getHappyString(int n, int k) {
        string current = "";

        vector<string> happy;

        generate(n, current, happy);

        if(happy.size()<k) return "";

        return happy[k-1];
    }

};