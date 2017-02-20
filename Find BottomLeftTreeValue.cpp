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
    int getLevel(TreeNode* root, int level){
        if(!root){
            return level-1;
        }
        
        return max(level, max(getLevel(root->left, level+1), getLevel(root->right, level+1)));
    }
    
    void getLeft(TreeNode* root, int level, int MAX_LEVEL, bool& found, int& ans){
        if(found || !root){
            return;
        }
        else if(level == MAX_LEVEL){
            ans = root->val;
            found = true;
            return;
        }
        
        getLeft(root->left, level+1, MAX_LEVEL, found, ans);
        getLeft(root->right, level+1, MAX_LEVEL, found, ans);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int maxLevel = getLevel(root, 0);
        
        bool found = false;
        
        int ans;
        
        getLeft(root, 0, maxLevel, found, ans);
        
        return ans;
    }
};
