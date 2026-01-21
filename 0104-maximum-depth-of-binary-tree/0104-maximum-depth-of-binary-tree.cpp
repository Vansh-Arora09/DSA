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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth=0;
        while(!q.empty()){
            int node = q.size();
            depth++;
            for(int i=0;i<node;i++){
                TreeNode* nd = q.front();
                q.pop();

                if(nd->left) q.push(nd->left);
                if(nd->right) q.push(nd->right);
            }
        }
        return depth;
    }
};