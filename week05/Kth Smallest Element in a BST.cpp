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
    class KthSmallestBST{
        private:
            stack<TreeNode*>bst;
            TreeNode* root;
        public:
            KthSmallestBST(TreeNode* _root){
                root = _root;
                TreeNode* current = root;
                while(current){
                    bst.push(current);
                    current = current->left;
                }
            }
            TreeNode* getNext(){
                TreeNode* result = bst.top();
                bst.pop();
                if(result->right){
                    TreeNode* current = result->right;
                    while(current){
                        bst.push(current);
                        current = current->left;
                    }
                }
            return result;
        }
    };
public:
    int kthSmallest(TreeNode* root, int k) {
        KthSmallestBST bst(root);
        TreeNode* result;
        for(int i=0; i<k; i++){
            result = bst.getNext();
        }
        return result->val;
    }
};