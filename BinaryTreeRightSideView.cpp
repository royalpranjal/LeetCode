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
    void tree(TreeNode* root, vector<vector<int> >& temp, int level){
        if(root == NULL){
            return;
        }
        
        if(level > temp.size()){
            vector<int> a;
            temp.push_back(a);
        }
        
        temp[level-1].push_back(root->val);
        
        tree(root->left, temp, level+1);
        tree(root->right, temp, level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol;
        vector<vector<int> > temp;
        
        tree(root, temp, 1);
        
        for(int i = 0; i < temp.size(); i++){
            sol.push_back(temp[i][temp[i].size()-1]);
        }
        
        return sol;
    }
};
