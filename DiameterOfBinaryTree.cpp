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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        else if(root->right == NULL && root->left == NULL){
            return 1;
        }
        
        return 1 + max(height(root->left), height(root->right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        return max(height(root->left) + height(root->right), max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
};
