class Trie {
    struct TrieNode{
        TrieNode* next[26];
        bool isWord;
        TrieNode(){
            isWord = false;
            for(auto &n:next){
                n = nullptr;
            }
        }
    };
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        for(auto &c:word){
            int i = c - 'a';
            cout<<i<<" ";
            if(!current->next[i]){
                current->next[i] = new TrieNode();
            }
            current = current->next[i];
        }
        current->isWord = true;
    }
    
    bool search(string word, bool prefix = false) {
        TrieNode* current = root;
        for(auto &c:word){
            int i = c - 'a';
            if(!current->next[i]){
                return false;
            }
            current=current->next[i];
        }
        if(prefix==false){
            return current->isWord;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */