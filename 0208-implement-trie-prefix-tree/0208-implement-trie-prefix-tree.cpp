class TrieNode {
public:
    char data;
    TrieNode* childrens[26] = {}; // initialize the every children with nullptr
    bool isTerminal;

    // constructor
    TrieNode(char data) {
        this->data = data;
        isTerminal = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }

    // insertion in the trie
    void insertUtil(TrieNode* root, string word, int i) {
        // base cond
        if (word.size() == i) {
            root->isTerminal = true;
            return;
        }
        // assumption word is in CAPS
        int index = word[i] - 'a'; // index in childrens array

        // if word[i] is not present
        if (root->childrens[index] == nullptr)
            root->childrens[index] = new TrieNode(word[i]);

        // recursion
        insertUtil(root->childrens[index], word, i + 1);
    }

    void insert(string word) {
        insertUtil(root, word, 0); 
    }

    bool search(string word) {
        TrieNode* temp = root;

        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (!temp->childrens[index] ||
                temp->childrens[index]->data != word[i]) {
                return false;
            }
            temp = temp->childrens[index];
        }

        if (temp->isTerminal)
            return true;

        return false;
    }

    bool startsWith(string prefix) {
        TrieNode* temp = root;

        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (!temp->childrens[index] ||
                temp->childrens[index]->data != prefix[i]) {
                return false;
            }
            temp = temp->childrens[index];
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