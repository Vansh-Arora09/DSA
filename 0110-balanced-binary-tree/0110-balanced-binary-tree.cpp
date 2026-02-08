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

    int check(TreeNode *node){
        if(!node){
            return true;
        }
        int lft = check(node->left);
        if(lft==-1) return -1;

        int rgt = check(node->right);
        if(rgt==-1) return -1;

        if(abs(lft-rgt)>1) return -1;
        return 1 + max(lft, rgt); 
    }
    bool isBalanced(TreeNode* root) {
        
        return check(root)!=-1;
    }
};