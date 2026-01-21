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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        queue<TreeNode*> qp;
        queue<TreeNode*> qq;

        qp.push(p);
        qq.push(q);

        while(!qp.empty() && !qq.empty()){
            TreeNode *nodp = qp.front();
            TreeNode* nodq = qq.front();
            qp.pop();
            qq.pop();
            if(nodp->val!=nodq->val) return false;

            if(nodp->left && nodq->left){
                qp.push(nodp->left);
                qq.push(nodq->left);
            }
            else if(nodp->left || nodq->left) return false;

            if(nodp->right && nodq->right){
                qp.push(nodp->right);
                qq.push(nodq->right);
            }
            else if(nodp->right || nodq->right) return false;
        }
        return true;
    }
};