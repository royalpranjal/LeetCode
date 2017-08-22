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
    int sum(TreeNode* root){
        if(!root){
            return 0;
        }
        return root->val + sum(root->left) + sum(root->right);
    }
    
    bool check(TreeNode* root, int total){
        if(!root){
            return false;
        }
        else if(!root->left && !root->right){
            return false;
        }
        else if(root->left && root->right){
            if(sum(root->left) == total+root->val+sum(root->right)){
                return true;
            }
            if(sum(root->right) == total+root->val+sum(root->left)){
                return true;
            }
            return check(root->left, total+root->val+sum(root->right)) || check(root->right, total+root->val+sum(root->left));
        }
        else if(root->left){
            if(sum(root->left) == total+root->val){
                return true;
            }
            return check(root->left, total+root->val);
        }
        if(sum(root->right) == total+root->val){
            return true;
        }
        return check(root->right, total+root->val);
    }
    
    bool checkEqualTree(TreeNode* root) {
        return check(root, 0);
    }
};
