/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* searchNode(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==p->val||root->val==q->val){
            return root;
        }
        auto lSearch=searchNode(root->left,p,q);
        auto rSearch=searchNode(root->right,p,q);
        if(lSearch&&rSearch){
            return root;
        }
        return lSearch?lSearch:rSearch;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return searchNode(root,p,q);
    }
};