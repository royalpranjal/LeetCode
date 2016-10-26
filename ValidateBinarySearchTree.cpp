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
    bool checkValid(TreeNode* root, long long int MAX, long long int MIN){
        if(root == NULL){
            return true;
        }    
        else if(root->val >= MAX || root->val <= MIN){
            return false;
        }
        return checkValid(root->left, (long long)root->val, MIN) & checkValid(root->right, MAX, (long long)root->val);
    }
    
    bool isValidBST(TreeNode* root) {
        return checkValid(root, LLONG_MAX, LLONG_MIN);    
    }
};
