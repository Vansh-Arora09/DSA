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
    vector<int> ans;
    void inord(TreeNode* root){
        if(!root) return;

        inord(root->left);
        ans.push_back(root->val);
        inord(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inord(root);
        return ans[k-1];
    }
};