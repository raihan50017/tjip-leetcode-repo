/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    string serialize_helper(TreeNode* root){
        if(root==nullptr){
            return "#";
        }
        return to_string(root->val)
               +","+serialize(root->left)
               +","+serialize(root->right);
    }
    void popolate_string(queue<string> &Q, string data){
        stringstream stream(data);
        string token;
        while(getline(stream,token,',')){
            Q.push(token);
        }
    }
    TreeNode* deserialize_helper(queue<string> &Q){
        if(Q.empty()){
            return nullptr;
        }
        auto element = Q.front();
        Q.pop();
        if(element=="#"){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(element));
        root->left = deserialize_helper(Q);
        root->right = deserialize_helper(Q);
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return serialize_helper(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string>Q;
        popolate_string(Q,data);
        return deserialize_helper(Q);
    }
};