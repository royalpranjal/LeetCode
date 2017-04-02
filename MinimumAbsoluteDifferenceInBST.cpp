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
    int diff(TreeNode* root, TreeNode* child, int& ans){
        if(!root){
            return ans;
        }
        
        if(child){
            ans = min(ans, min(abs(root->val - child->val), min(diff(root, child->left, ans), diff(root, child->right, ans))));
        }
        
        return ans;
    }

    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        
        if(!root){
            return ans;
        }
        
        ans = min(ans, min(diff(root, root->left, ans), min(diff(root, root->right, ans), min(getMinimumDifference(root->left), getMinimumDifference(root->right)))));
        
        return ans;
    }
};
