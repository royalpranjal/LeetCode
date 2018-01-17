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
    void find(TreeNode* root, string str, vector<string>& temp){
        if(root == NULL){
            return;
        }
        else if(root->left == NULL && root->right == NULL){
            str = str + to_string((int)root->val);
            temp.push_back(str);
        }
        else if(root->left == NULL){
            str = str + to_string((int)root->val) + "->";
            find(root->right, str, temp);
        }
        else if(root->right == NULL){
            str = str + to_string((int)root->val) + "->";
            find(root->left, str, temp);
        }
        else{
            str = str + to_string((int)root->val) + "->";
            find(root->left, str, temp);
            find(root->right, str, temp);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> temp;
        
        find(root, "", temp);
        
        return temp;
    }
};
