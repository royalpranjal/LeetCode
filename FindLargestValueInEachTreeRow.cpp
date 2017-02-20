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
    void store(TreeNode* root, vector<int>& sol, int level){
        if(!root){
            return;
        }
        
        if(level > sol.size()){
            sol.push_back(root->val);
        }
        else{
            if(sol[level-1] < root->val){
                sol[level-1] = root->val;
            }
        }
        
        store(root->left, sol, level+1);
        store(root->right, sol, level+1);
        
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> sol;
        
        store(root, sol, 1);
        
        return sol;
    }
};
