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
private:
    vector<int>nodes;
    void traverseTree(TreeNode* root){
        if(root==nullptr){
            return;
        }
        traverseTree(root->left);
        nodes.push_back(root->val);
        traverseTree(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        traverseTree(root);
        return is_sorted(nodes.begin(),nodes.end()) && adjacent_find(nodes.begin(),nodes.end())==nodes.end();
    }
};