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
    void make(TreeNode* root, int v, int d){
        if(!root){
            return;
        }
        else if(d == 1){
            TreeNode* lft = new TreeNode(v);
            TreeNode* ryt = new TreeNode(v);
            
            lft->left = root->left;
            ryt->right = root->right;
            
            root->left = lft;
            root->right = ryt;
            
            return;
        }
        make(root->left, v, d-1);
        make(root->right, v, d-1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        
        make(root, v, d-1);
        
        return root;
    }
};
