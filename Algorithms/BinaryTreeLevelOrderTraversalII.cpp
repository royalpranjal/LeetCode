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
    void level(TreeNode* root, vector<vector<int> >& sol, int lev){
        if(root == NULL){
            return;
        }
        
        if(sol.size() < lev){
            vector<int> temp;
            sol.insert(sol.begin(), temp);
        }
        
        sol[sol.size()-lev].push_back(root->val);
        
        level(root->left, sol, lev+1);
        level(root->right, sol, lev+1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > sol;
        
        level(root, sol, 1);
        
        return sol;
    }
};
