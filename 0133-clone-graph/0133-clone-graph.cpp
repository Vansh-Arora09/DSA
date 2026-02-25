/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;

        unordered_map<Node*, Node*> visited;

        queue<Node*> q;

        visited[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(auto neigh : curr->neighbors){
                if(!visited[neigh]){
                    visited[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }

                visited[curr]->neighbors.push_back(visited[neigh]); 
            }
        }
        return visited[node];
    }
};