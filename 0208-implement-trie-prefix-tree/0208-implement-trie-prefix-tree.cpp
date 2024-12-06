class Trie {
private:
struct Node {
    Node* children[26]; // Array to store child nodes for 'a' to 'z'
    bool isEndOfWord;   // Marks end of a word

    Node() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        // first check to see if first letter is at the top layer
        Node* node = root;
        for(char c: word){
            int index = c - 'a'; // to get the index from a = 0
            // if this letter isn't in our char array marked with ptr
            // then create it
            if(!node->children[index]){
                node->children[index] = new Node();
            }
            // now in either case, we move onto the next letter and onto the next node
            // because it either already existed or we just created it
            node = node->children[index];
        }
        // now our node ptr is at the very end of the word
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        // assuming it has to be the exact word and not partial fulfillment
        Node* node = root;
        for(char c: word){
            int index = c - 'a';
            if(!node->children[index]){
                return false;
            }
            node = node->children[index];
        }
        if(!node->isEndOfWord){
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char c: prefix){
            int index = c - 'a';
            if(!node->children[index]){
                return false;
            }
            node = node->children[index];
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