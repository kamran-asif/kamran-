class WordDictionary {
private:
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) child[i] = nullptr;
        }
    };

    TrieNode* root;

    bool dfs(TrieNode* node, const string& word, int idx) {
        if (!node) return false;
        if (idx == (int)word.size()) return node->isEnd;

        char ch = word[idx];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (dfs(node->child[i], word, idx + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            return dfs(node->child[ch - 'a'], word, idx + 1);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int id = ch - 'a';
            if (!node->child[id]) {
                node->child[id] = new TrieNode();
            }
            node = node->child[id];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};