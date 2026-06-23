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
    TreeNode* insert(TreeNode* root, int n){
        if(!root) return new TreeNode(n);

        if(n<root->val){
            root->left = insert(root->left, n);
        }
        else{
           root->right = insert(root->right, n);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;

        TreeNode* srt = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insert(srt, preorder[i]);
        }
        return srt;
    }
};