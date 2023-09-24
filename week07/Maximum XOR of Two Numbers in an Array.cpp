class Solution {
private: 
    class TrieNode{
        public:
        TrieNode* next[2];
        TrieNode(){
            next[0] = next[1] = nullptr;
        }
    };
    class Trie{
        public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
        void insert(int val){
            TrieNode* current = root;
            for(int i=30; i>=0; i--){
                bool currBit = (val & (1<<i)) > 0 ? 1 : 0;
                if(current->next[currBit]==nullptr){
                    current->next[currBit] = new TrieNode();
                }
                current = current->next[currBit];
            }
        }
        int findMaxXOR(int val){
            TrieNode* current = root;
            int num = 0;
            for(int i=30; i>=0; i--){
                bool currBit = (val & (1<<i)) > 0 ? 1 : 0;
                bool oppBit = currBit ^ 1;
                if(current->next[oppBit]){
                    num = num | (1<<i);
                    current = current->next[oppBit];
                }
                else{
                    current = current->next[currBit];
                }
            }
            return num;
        }
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        int maxVal = 0;
        trie->insert(nums[0]);
        for(int i=1; i<nums.size(); i++){
            maxVal = max(maxVal, trie->findMaxXOR(nums[i]));
            trie->insert(nums[i]);
        }
        return maxVal;
    }
};