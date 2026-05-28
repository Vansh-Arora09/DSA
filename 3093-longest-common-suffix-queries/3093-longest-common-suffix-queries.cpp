class Solution {

    struct TrieNode{
        int child[26];
        int best_idx;
    };

    bool is_better(int new_idx, int idx, vector<string>&wordContainer){
        if(wordContainer[new_idx].length()!=wordContainer[idx].length()){
            return wordContainer[new_idx].length()<wordContainer[idx].length();
        }
        return new_idx<idx;
    }
public:
    vector<int> stringIndices(vector<string>& wordContainer, vector<string>& wordsQuery) {
        int best_idx = 0;
        for(int i=1;i<wordContainer.size();i++){
            if(wordContainer[i].length()<wordContainer[best_idx].length()){
                best_idx = i;
            }
        }
        vector<TrieNode> trie;
        auto create = [&](int idx){
            TrieNode node;
            node.best_idx = idx;
            for(int i=0;i<26;i++){
                node.child[i]=-1;
            }
            trie.push_back(node);
        };
        create(best_idx);

        for(int i=0;i<wordContainer.size();i++){
            const string &word = wordContainer[i];
            int curr_node_idx=0;

            for(int j = word.length()-1;j>=0;j--){
                int char_idx = word[j]-'a';
                if(trie[curr_node_idx].child[char_idx]==-1){
                    int next_idx = trie.size();
                    create(i);
                    trie[curr_node_idx].child[char_idx] = next_idx;
                }
                else{
                    int next_node_idx = trie[curr_node_idx].child[char_idx];
                    if(is_better(i, trie[next_node_idx].best_idx,wordContainer)){
                        trie[next_node_idx].best_idx = i;
                    }
                }
                curr_node_idx = trie[curr_node_idx].child[char_idx];
            }
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for(const auto &query : wordsQuery){
            int curr_node_idx=0;

            for(int i=query.length()-1;i>=0;i--){
                int char_idx = query[i]-'a';
                if(trie[curr_node_idx].child[char_idx]!=-1){
                    curr_node_idx = trie[curr_node_idx].child[char_idx];
                }
                else{
                    break;
                }
            }
            ans.push_back(trie[curr_node_idx].best_idx);
        }
        return ans;
    }
};