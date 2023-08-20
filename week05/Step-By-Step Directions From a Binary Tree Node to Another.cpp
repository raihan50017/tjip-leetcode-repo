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
    TreeNode* findLCA(TreeNode* root, int startValue, int destValue){
        if(root==nullptr){
            return nullptr; 
        }
        if(root->val==startValue||root->val==destValue){
            return root;
        }
        TreeNode* lSearch = findLCA(root->left,startValue,destValue);
        TreeNode* rSearch = findLCA(root->right,startValue,destValue);
        if(lSearch && rSearch){
            return root;
        }
        return lSearch?lSearch:rSearch;
    }
bool findPath(TreeNode* root, int val, string &path){
    if(root->val==val){
        return true;
    }

    if(root->left && findPath(root->left,val,path)){
        path.push_back('L');
    }
    else if(root->right && findPath(root->right,val,path)){
         path.push_back('R');
    }
    return !path.empty();
}
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root,startValue,destValue);
        string sPath, dPath;
        findPath(lca,startValue,sPath);
        findPath(lca,destValue,dPath);
        return string(sPath.size(),'U')+string(rbegin(dPath),rend(dPath));
    }
};