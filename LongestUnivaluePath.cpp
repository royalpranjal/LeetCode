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
    int parChild(TreeNode* root, int par){
        if(!root){
            return 0;
        }
        else if(root->val == par){
            return 1 + max(parChild(root->left, par), parChild(root->right, par));
        }
        
        return 0;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(!root){
            return 0;
        }
        return max(max(longestUnivaluePath(root->left), longestUnivaluePath(root->right)), 
                  parChild(root->left, root->val) + parChild(root->right, root->val));
    }
};
