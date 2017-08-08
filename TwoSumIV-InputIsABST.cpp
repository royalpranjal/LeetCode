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
    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return false;
        }
        
        vector<int> temp;
        
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while(curr != NULL || !st.empty()){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }
            else{
                temp.push_back((st.top())->val);
                curr = (st.top())->right;
                st.pop();
            }
        }
            
        int i = 0, j = temp.size()-1;
        
        while(i < j){
            int sum = temp[i] + temp[j];
            if(sum == k){
                return true;
            }
            else if(sum > k){
                j--;
            }
            else{
                i++;
            }
        }
        

        return false;
    }
};
