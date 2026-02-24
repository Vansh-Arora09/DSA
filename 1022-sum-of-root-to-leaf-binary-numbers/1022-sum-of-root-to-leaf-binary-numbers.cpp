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

    int recfun(TreeNode* root, int curr){
        if(!root) return 0;

        curr = curr*2 + root->val;
        if(!root->left && !root->right){
            return curr;
        }

        return recfun(root->left, curr) + recfun(root->right, curr);
    }
    int sumRootToLeaf(TreeNode* root) {
        return recfun(root,0);
    }
};