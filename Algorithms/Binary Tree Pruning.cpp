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
public:
    bool search(TreeNode* root){
        if(!root){
            return false;
        }
        else if(root->val == 1){
            return true;
        }
        
        return search(root->left) || search(root->right);
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(!search(root)){
            return NULL;
        }
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        
        return root;
    }
};
