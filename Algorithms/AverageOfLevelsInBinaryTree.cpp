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
    void make(TreeNode* root, vector<vector<long long int> > & temp, int level){
        if(!root){
            return;
        }
        
        if(temp.size() < level){
            vector<long long int> a(2, 0);
            temp.push_back(a);
        }
        
        temp[level-1][0] += root->val;
        temp[level-1][1] ++;
        
        make(root->left, temp, level+1);
        make(root->right, temp, level+1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        
        if(!root){
            return ans;
        }
        
        vector<vector<long long int> > temp;
        
        make(root, temp, 1);
        
        for(int i = 0; i < temp.size(); i++){
            ans.push_back((double)temp[i][0]/temp[i][1]);
        }
        
        return ans;
    }
};
