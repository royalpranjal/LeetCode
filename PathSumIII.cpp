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
    void check(TreeNode* root, int& ans, int sum){
        if(root == NULL){
            return;
        }
        if(root->val == sum){
            ans++;
        }
        check(root->left, ans, sum-root->val);
        check(root->right, ans, sum-root->val);
    }
    
    void checkSum(TreeNode* root, int& ans, int sum){
        if(root == NULL){
            return;
        }    
        check(root, ans, sum);
        checkSum(root->left, ans, sum);
        checkSum(root->right, ans, sum);
    }
    
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        checkSum(root, ans, sum);
        return ans;
    }
};
