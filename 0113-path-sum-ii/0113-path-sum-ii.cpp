/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void solve(TreeNode* root, int targetSum, vector<int>&single, vector<vector<int>>& res){
        if(!root) return;

        single.push_back(root->val);

        if(targetSum==root->val && !root->left && !root->right){
            res.push_back(single);
        }

        solve(root->left, targetSum-root->val, single, res);
        solve(root->right, targetSum-root->val, single, res);

        single.pop_back();


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> single;

        solve(root, targetSum, single, res);
        return res;
    }
};