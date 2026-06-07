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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodemap;
        unordered_set<int> st;

        for(const auto& des : descriptions){
            int parent = des[0];
            int child = des[1];
            bool isleft = des[2]==1;

            if(nodemap.find(parent)==nodemap.end()){
                nodemap[parent] = new TreeNode(parent);
            }

            if(nodemap.find(child)==nodemap.end()){
                nodemap[child] = new TreeNode(child);
            }

            if(isleft){
                nodemap[parent]->left = nodemap[child];
            }
            else{
                nodemap[parent]->right = nodemap[child];
            }
            st.insert(child);
        }

        for(auto& nd : nodemap){
            int potparent = nd.first;
            if(st.find(potparent)==st.end()){
                return nd.second;
            }
        }
        return nullptr;
    }
};