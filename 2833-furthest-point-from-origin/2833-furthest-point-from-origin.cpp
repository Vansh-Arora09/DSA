class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l_cnt=0, r_cnt=0, sp_cnt=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L') l_cnt++;
            if(moves[i]=='R') r_cnt++;
            if(moves[i]=='_') sp_cnt++;
        }

        int maxi=0;

        maxi = max(abs(l_cnt+sp_cnt - r_cnt), abs(r_cnt+sp_cnt - l_cnt));
        return maxi;
    }
};