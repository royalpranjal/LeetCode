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
    bool check(TreeNode* root, TreeNode* temp){
        if(!root && !temp){
            return true;
        }    
        else if(!root){
            return false;
        }
        else if(!temp){
            return false;
        }
        else if(root->val != temp->val){
            return false;
        }
        
        return check(root->left, temp->left) && check(root->right, temp->right);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t){
            return false;
        } 
        else if(!s){
            return false;
        }
        else if(!t){
            return false;
        }
        
        if(s->val == t->val){
            bool ans = check(s->left, t->left) && check(s->right, t->right);
            if(ans){
                return true;
            }
        }
        
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
