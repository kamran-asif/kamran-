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
    void insertUtil(TrieNode* root, string& word, int i) {
        // base cond
        if ( i == -1 ) {
            root->isTerminal = true;
            return;
        }
        // assumption word is in lowercase
        int index = word[i] - 'a'; // index in childrens array

        // if word[i] is not present
        if (root->childrens[index] == nullptr)
            root->childrens[index] = new TrieNode(word[i]);

        // recursion
        insertUtil(root->childrens[index], word, i - 1);
    }

    void insert(string& word) {
        int i = word.length() - 1;
        insertUtil(root, word, i); 
    }

    void utilcountAllTrieStrings(TrieNode* root,int& ans, int count){
        bool hasChild = false; // for current node has child or not
        // dfs for counting nodes
        for(auto child :root->childrens){
            if(child){
                hasChild = true;
                utilcountAllTrieStrings(child,ans, count + 1);
            }
        }

        // update ans , only if root node is the last node of the branch(condn: it should be terminal and it does not have any child node)
        if(root->isTerminal && !hasChild) {        
            ans += count + 1; // +1 for #
        }
    }
    int countAllTrieStrings(){
        int ans = 0;
        utilcountAllTrieStrings(root,ans,0);
        return ans;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
    // Use a Trie to store reversed words and sum lengths of leaf nodes to find shortest encoding.

        Trie t;
        for(string word : words){
            t.insert(word); // insertion in reverse order
        }
        return t.countAllTrieStrings(); //  count all the unique strings formed
    }
};