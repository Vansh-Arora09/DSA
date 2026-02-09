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
    void inordertraverse(TreeNode* root, vector<int>&inorder){
        if(root==nullptr) return ;

        inordertraverse(root->left, inorder);
        inorder.push_back(root->val);
        inordertraverse(root->right, inorder);
    }

    TreeNode* create(vector<int>inorder, int start, int end){
        
        if(start>end) return nullptr;
        int mid = start+(end-start)/2;

        TreeNode* leftsub = create(inorder, start, mid-1);
        TreeNode* rightsub = create(inorder, mid+1,end);

        return new TreeNode(inorder[mid],leftsub,rightsub);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inordertraverse(root, inorder);

        int size = inorder.size();

        return create(inorder, 0, size-1);

    }
};