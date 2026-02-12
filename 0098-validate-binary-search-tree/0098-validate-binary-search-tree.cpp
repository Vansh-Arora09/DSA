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

    bool isbst(TreeNode* root, long long minm = LLONG_MIN, long long maxm = LLONG_MAX) {
        if(!root) return true;

        if(root->val>=maxm || root->val<=minm){
            return false;
        }
        return isbst(root->left, minm, root->val) && isbst(root->right,root->val,maxm);
    }

    bool isValidBST(TreeNode* root) {
       return isbst(root);
    }
};