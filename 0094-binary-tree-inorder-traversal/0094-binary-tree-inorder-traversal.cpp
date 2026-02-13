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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr!=NULL){
            // does curr hav eleft child
            //find the inorder predecessor IP
            if(curr->left!=NULL){
                TreeNode* ip = curr->left;
                while(ip->right!=NULL && ip->right!=curr){
                    ip = ip->right;
                }
                if(ip->right==NULL){
                    //pesudo link creation

                    ip->right = curr;
                    curr = curr->left;
                }
                else{
                    //print curr node and delete link and move to right
                    ans.push_back(curr->val);
                    ip->right = NULL;
                    curr = curr->right;
                }
            }
            else{
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};