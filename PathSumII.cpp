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
    void sumy(TreeNode* root, int sum, vector<vector<int> >& sol, vector<int> temp){
        if(root == NULL){
            return;
        }
        else if(root->left == NULL && root->right == NULL){
            if(root->val == sum){
                temp.push_back(root->val);
                sol.push_back(temp);
            }
            return;
        }
        else if(root->left != NULL && root->right != NULL){
            temp.push_back(root->val);
            sumy(root->left, sum - root->val, sol, temp);
            sumy(root->right, sum - root->val, sol, temp);
        }
        else if(root->left != NULL){
            temp.push_back(root->val);
            sumy(root->left, sum - root->val, sol, temp);
        }
        else if(root->right != NULL){
            temp.push_back(root->val);
            sumy(root->right, sum - root->val, sol, temp);
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > sol;
        vector<int> temp;
        
        sumy(root, sum, sol, temp);
        
        return sol;
    }
};
