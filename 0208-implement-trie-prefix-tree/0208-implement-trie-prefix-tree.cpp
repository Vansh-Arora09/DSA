class Trie {
public:
    Trie* v[26];
    bool end;
    Trie() {
        end = false;
        for (int i = 0; i < 26; i++) {
            v[i] = nullptr;
        }
    }

    void insert(string word) {
        int n = word.size();
        Trie* root = this;
        Trie* curr = root;
        for (int i = 0; i < n; i++) {
            if (curr->v[word[i] - 'a'] == nullptr) {
                curr->v[word[i] - 'a'] = new Trie();
            }
            curr = curr->v[word[i] - 'a'];
        }
        curr->end = true;
    }

    bool search(string word) {
        int n = word.size();
        Trie* curr = this;
        for (int i = 0; i < n; i++) {
            if (curr->v[word[i] - 'a'] == nullptr) {
                return false;
            }
            curr = curr->v[word[i] - 'a'];
        }
        return curr->end;
    }

    bool startsWith(string prefix) {
        int n = prefix.length();
        Trie* curr = this;
        for (int i = 0; i < n; i++) {
            if (curr->v[prefix[i] - 'a'] == nullptr)
                return false;
            curr = curr->v[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */