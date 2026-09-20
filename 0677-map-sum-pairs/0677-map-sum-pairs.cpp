class TrieNode {
public:
    char data;
    TrieNode* childrens[26] = {}; // initialize the every children with nullptr
    bool isTerminal = false;
    int val = 0;

    // constructor
    TrieNode(char data) {
        this->data = data;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }

    // insertion in the trie
    void insertUtil(TrieNode* root, string word, int i ,int val ) {
        // base cond
        if (word.size() == i) {
            root->isTerminal = true;
            root->val = val;
            return;
        }
        // assumption word is in lowercase
        int index = word[i] - 'a'; // index in childrens array

        // if word[i] is not present
        if (root->childrens[index] == nullptr)
            root->childrens[index] = new TrieNode(word[i]);

        // recursion
        insertUtil(root->childrens[index], word, i + 1,val);
    }

    void insert(string word , int val) {
        insertUtil(root, word, 0 , val); 
    }
    //
    void utilStartsWith(TrieNode* root,string& prefix, int& sum , int i){
        if( i >= prefix.size()){ // if prefix string got completes
            if( root->isTerminal) sum += root->val; // if terminal than take key -> val
            for(auto child : root->childrens){ // recursively get all the prefix strings
                if( child != nullptr){
                    utilStartsWith(child,prefix,sum , i+1);
                }
            }
            return ; // all child got traverse , nothing left so return
        }

        int index = prefix[i] - 'a';
        if(root->childrens[index] == nullptr){ // prefix breaks so return
            return ;
        }
        
        utilStartsWith(root->childrens[index],prefix,sum ,i+1);

    }
    int startsWith(string prefix) {
        int sum = 0;
        utilStartsWith(root, prefix, sum , 0);
        return sum;
    }
};

class MapSum {
public:
    Trie t;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        t.insert(key,val); 
    }
    
    int sum(string prefix) {
        return t.startsWith(prefix); 
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */