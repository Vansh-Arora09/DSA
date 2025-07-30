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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(root->val<key){
            root->right = deleteNode(root->right,key);
        }
        else if(root->val>key){
            root->left = deleteNode(root->left,key);
        }
        else{
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }

            if(root->left==NULL){
                return root->right;
            }
            else if(root->right==NULL){
                return root->left;
            }

            TreeNode* mini = find(root->right);
            root->val = mini->val;

            root->right = deleteNode(root->right,mini->val);
        }
        return root;
    }
    TreeNode* find(TreeNode* root){
        while(root->left!=NULL){
            root = root->left;
        }
        return root;
    }
};