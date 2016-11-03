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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        
        if(root == p || root == q){
            return root;
        }
        
        TreeNode* lft = lowestCommonAncestor(root->left, p, q);
        TreeNode* ryt = lowestCommonAncestor(root->right, p, q);
        
        if(lft != NULL && ryt != NULL){
            return root;
        }
        else if(lft != NULL){
            return lft;
        }
        else if(ryt != NULL){
            return ryt;
        }
        
        return NULL;
    }
};
