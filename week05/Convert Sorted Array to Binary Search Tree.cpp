0/5
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
TreeNode* constructBST(int L, int R, vector<int>& nums){
    if(L>R){
        return nullptr;
    }
    int mid = (L+R)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = constructBST(L, mid-1, nums);
    root->right = constructBST(mid+1, R, nums);
    return root;
}
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(0, nums.size()-1, nums);
    }
};