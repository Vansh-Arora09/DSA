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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> bfs;

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            bfs.push_back(curr ? 1 : -1);
            if(curr!=NULL) q.push(curr->left);
            if(curr!=NULL) q.push(curr->right);
        }

        bool found=false;
        for(int i : bfs){
            if(i==-1){
                found=true;
            }
            if(found && i!=-1) return false;
        }
        return true;

    }
};