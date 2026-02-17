class Solution {
public:
    void backtrack(vector<string>&ans, int value[], int h, int m, int idx, int cnt, int total){
        if(cnt == total){
            if(h<12 && m<60) {
                string time = to_string(h) + ":" + (m<10 ? "0" : "") + to_string(m);
                ans.push_back(time);
            }
            return ;
        }

        if(idx==10) return;

        if(idx<4){
            backtrack(ans,value,h + value[idx], m, idx+1, cnt+1, total);
        }
        else{
            backtrack(ans, value, h, m + value[idx], idx+1, cnt+1, total);
        }
        //keep the led off
        backtrack(ans, value, h, m,idx+1, cnt,total);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        int value[10] = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1};
        vector<string> ans;
        backtrack(ans,value,0, 0, 0, 0, turnedOn);
        return ans;
    }
};