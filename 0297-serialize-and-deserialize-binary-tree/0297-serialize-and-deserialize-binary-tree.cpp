class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans="";
        queue<TreeNode*> q;
        ans+=to_string(root->val);
        ans+=",";
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
                ans+=to_string(node->left->val);
                ans+=",";
            }
            else{
                ans+="null,";
            }
            if(node->right){
                q.push(node->right);
                ans+=to_string(node->right->val);
                ans+=",";
            }
            else{
                ans+="null,";
            }
        }
        //cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;

        stringstream ss(data);
        string curr = "";
        getline(ss,curr,',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(curr));
        q.push(root);
        while(q.size()){
            TreeNode* currnode = q.front();
            q.pop();
            getline(ss, curr, ',');
            if(curr=="null"){
                currnode->left = NULL;
            }
            else{
                currnode->left = new TreeNode(stoi(curr));
                q.push(currnode->left);
            }
            getline(ss, curr, ',');
            if(curr=="null"){
                currnode->right = NULL;
            }
            else{
                currnode->right = new TreeNode(stoi(curr));
                q.push(currnode->right);
            }

        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));