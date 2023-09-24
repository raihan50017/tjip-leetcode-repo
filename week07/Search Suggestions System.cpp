class Solution {
private:
    class TrieNode{
        public:
        TrieNode* next[26];
        bool isEnd;
        TrieNode(){
            isEnd = false;
            for(int i=0; i<26; i++){
                next[i] = nullptr;
            }
        }
    };
    class Trie{
        public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
        void insert(string &word){
            TrieNode* current = root;
            for(auto ch : word){
                int i = ch - 'a';
                if(current->next[i]==nullptr){
                    current->next[i]=new TrieNode();
                }
                current = current->next[i];
            }
            current->isEnd = true;
        }
    };
    void constructSggetions(TrieNode* current, string &currentWord, vector<string>&result){
        if(current==nullptr || result.size()==3){
            return;
        }
        if(current->isEnd==true){
            result.push_back(currentWord);
        }
        for(int i=0; i<26; i++){
            if(current->next[i]){
                currentWord.push_back((char)(i+'a'));
                constructSggetions(current->next[i],currentWord,result);
                currentWord.pop_back();
            }
        }
    }
    TrieNode* root;
    void initialize(vector<string>& products){
        Trie* trie = new Trie();
        root = trie->root;
        for(auto word : products){
            trie->insert(word);
        }
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
       initialize(products);
       vector<vector<string>>suggetions;
       string typedWord;
       TrieNode* current = root;
       for(auto ch: searchWord){
           int i = ch - 'a';
           current = current?current->next[i]:nullptr;
           vector<string>result;
           typedWord.push_back(ch);
           constructSggetions(current, typedWord, result);
           suggetions.push_back(result);
       }
       return suggetions;
    }
};