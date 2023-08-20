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
    vector<vector<int>> zigzagLevelOrderTraverse(TreeNode* root){
        vector<vector<int>>results;
         if(!root){
            return results;
        }
        queue<TreeNode*>Q;
        bool flag=false;
        Q.push(root);
        while(!Q.empty()){
            int size = Q.size();
            vector<int>temp;
            for(int i=0; i<size; i++){
                TreeNode* tempNode = Q.front();
                Q.pop();
                temp.push_back(tempNode->val);
                if(tempNode->left){
                    Q.push(tempNode->left);
                }
                if(tempNode->right){
                    Q.push(tempNode->right);
                }
            }
            if(flag){
                reverse(temp.begin(),temp.end());
                flag=false;
            }
            else{
                flag=true;
            }
            results.push_back(temp);
        }
        return results;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return zigzagLevelOrderTraverse(root);
    }
};