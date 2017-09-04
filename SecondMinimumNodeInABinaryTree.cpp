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
    void make(int& f, int& s, int val){
        if(f == INT_MAX){
            f = val;
        }
        else if(f == val){
            return;
        }
        else if(s == INT_MAX){
            int temp = f;
            f = min(f, val);
            s = max(temp, val);
        }
        else{
            if(f > val){
                s = f;
                f = val;
            }
            else if(s > val){
                s = val;
            }
        }
    }
    
    void check(TreeNode* root, int& f, int& s){
        if(!root){
            return;
        }
        make(f, s, root->val);
        check(root->left, f, s);
        check(root->right, f, s);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int fMin = INT_MAX, sMin = INT_MAX;
        check(root, fMin, sMin);
        
        if(sMin == INT_MAX){
            return -1;
        }
        
        return sMin;
    }
};
