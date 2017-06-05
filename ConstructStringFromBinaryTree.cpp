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
    void make(TreeNode* t, string& s){
        if(!t){
            return;    
        }
        
        s = s + to_string(t->val);        
        
        if(!t->left && !t->right){
            return;
        }
        
        s = s + "(";
        
        if(!t->left && t->right){
            s = s + ")(";
            make(t->right, s);
            s = s + ")";
            return;
        }
        else if(t->left && !t->right){
            make(t->left, s);
            s = s + ")";
            return;
        } 
        
        make(t->left, s);
        s = s + ")(";
        make(t->right, s);
        
        s = s + ")";
    }

    string tree2str(TreeNode* t) {
        string ans = "";
        
        make(t, ans);
        
        return ans;
    }
};
