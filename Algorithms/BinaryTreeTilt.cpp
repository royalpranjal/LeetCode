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
    int getSum(TreeNode* root){
        if(!root){
            return 0;
        }
        return root->val + getSum(root->left) + getSum(root->right);
    }
    
    void check(TreeNode* root, int& ans){
        if(!root){
            return;
        }
        
        int lft = getSum(root->left), ryt = getSum(root->right);
        
        ans = ans + abs(lft - ryt);
        
        check(root->left, ans);
        check(root->right, ans);
    }
    
    int findTilt(TreeNode* root) {
        int ans = 0;
        
        check(root, ans);
        
        return ans;
    }
};
