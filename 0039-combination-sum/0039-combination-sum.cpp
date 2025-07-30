class Solution {
public:

    void makeComb(vector<int>&candidates,int remsum, vector<int>&curr,vector<vector<int>>&res , int index){
        if(remsum==0){
            res.push_back(curr);
            return;
        }
        if(remsum<0 || index>=candidates.size()){
            return;
        }
        curr.push_back(candidates[index]);
        makeComb(candidates,remsum-candidates[index],curr,res,index);
        curr.pop_back();
        makeComb(candidates,remsum,curr,res,index+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        vector<vector<int>> res;

        makeComb(candidates,target,curr,res,0);
        return res;
    }
};