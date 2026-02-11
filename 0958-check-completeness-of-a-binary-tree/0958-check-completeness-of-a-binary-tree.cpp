class Solution {
public:
    int cntNodes(TreeNode* root){
        if(!root) return 0;

        return 1 + cntNodes(root->left) + cntNodes(root->right);
    }
    bool dfs(TreeNode* root, int idx, int cnt){
        if(!root) return true;

        if(idx > cnt) return false;

        return dfs(root->left,2*idx, cnt) && dfs(root->right, 2*idx+1,cnt);
    }

    bool isCompleteTree(TreeNode* root) {
        int total = cntNodes(root);
        return dfs(root, 1, total);


    }
};