/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>duplicate;
        calculateDuplicate(root, duplicate);
        return duplicate;
    }
private:
    unordered_map<string,int>hashes;
    string calculateDuplicate(TreeNode* root, vector<TreeNode*> &duplicate){
        if(root==NULL){
            return "#";
        }
        string leftHash = calculateDuplicate(root->left, duplicate);
        string rightHash = calculateDuplicate(root->right, duplicate);
        string currentHash = to_string(root->val) + "," + leftHash + "," + rightHash;
        if(hashes.count(currentHash) && hashes[currentHash]==1){
            duplicate.push_back(root);
        }
        hashes[currentHash]++;
        return currentHash;
    }
};