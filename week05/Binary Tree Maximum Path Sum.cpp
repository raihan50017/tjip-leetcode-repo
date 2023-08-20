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
    int MAX_SUM =INT_MIN;
    int findMax(TreeNode* root){
        if(!root){
            return 0;
        }
        int L = max(findMax(root->left),0);
        int R = max(findMax(root->right),0);
        MAX_SUM = max(MAX_SUM,(L+R+root->val));
        return max(L,R)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        return max(findMax(root),MAX_SUM);
    }
};