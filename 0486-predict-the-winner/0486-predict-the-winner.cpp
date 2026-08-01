class Solution {
public:
    bool rec(vector<int>&nums, int i, int j, int sc1=0, int sc2=0){
        if(i>j){
            return sc1>=sc2;
        }
        if(i==j){
            return rec(nums, i+1, j-1, sc1+nums[i], sc2);
        }
        // player1 -> start, player2 -> start+1;
        int op1 = rec(nums, i+2,j, sc1+nums[i], sc2 + nums[i+1]);
        // player1 -> start, player2 -> end;
        int op2 = rec(nums, i+1, j-1, sc1+nums[i], sc2+nums[j]);
        // player1 -> end, player2 -> start;
        int op3 = rec(nums, i+1, j-1, sc1+nums[j], sc2+nums[i]);
        // player1 -> end, player2 -> end-1;
        int op4 = rec(nums, i, j-2, sc1+nums[j] , sc2+nums[j-1]);

        return (op1 && op2) || (op3 && op4);
    }
    bool predictTheWinner(vector<int>& nums) {
        return rec(nums, 0, nums.size()-1);
    }
};