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
    int maxLevelSum(TreeNode* root) {
        int maxsum=INT_MIN;
        int ans=0;
        int level=0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            level++;
            int sumatlevel=0;
            
            for(int i=q.size();i>0;i--){
                TreeNode* node = q.front();
                q.pop();
                sumatlevel+= node->val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(maxsum < sumatlevel){
                maxsum = sumatlevel;
                ans = level;
            }
        }
        return ans;
    }
};