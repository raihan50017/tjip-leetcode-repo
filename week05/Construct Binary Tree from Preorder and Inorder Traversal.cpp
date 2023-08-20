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
    int preIndex = 0;
    int findInPos(vector<int>& inorder, int num){
        int i;
        for(i=0; i<inorder.size(); i++){
            if(num==inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int L, int R){
        if(L>R){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        if(L==R){
            return root;
        }
        int inIndex = findInPos(inorder,root->val);
        root->left=buildTree(preorder,inorder,L,inIndex-1);
        root->right=buildTree(preorder,inorder,inIndex+1,R);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,inorder,0,preorder.size()-1);
    }
};