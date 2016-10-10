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
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        
        TreeNode* curr = root, *last = root;
        
        while(!st.empty() || curr != NULL){
            if(curr != NULL){
                if(curr->right != NULL){
                    st.push(curr->right);
                }
                last = curr;
                curr = curr->left;
            }
            else{
                curr = st.top();
                st.pop();
                last->left = curr;
                last = curr;
            }
        }
        
        curr = root;
        
        while(curr != NULL){
            curr->right = curr->left;
            TreeNode* temp = curr->left;
            curr->left = NULL;
            
            curr = temp;
        }
    }
};
