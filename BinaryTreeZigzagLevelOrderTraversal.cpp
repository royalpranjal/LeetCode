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
    void zig(TreeNode* root, vector<vector<int> >& sol, bool left, int level){
        if(root == NULL){
            return;
        }
        
        if(sol.size() < level){
            vector<int> temp;
            sol.push_back(temp);
        }
        
        if(left){
            sol[level-1].push_back(root->val);
        }
        else{
            sol[level-1].insert(sol[level-1].begin(), root->val);
        }
        
        zig(root->left, sol, !left, level+1);
        zig(root->right, sol, !left, level+1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > sol;
        
        zig(root, sol, true, 1);
        
        return sol;
    }
};
