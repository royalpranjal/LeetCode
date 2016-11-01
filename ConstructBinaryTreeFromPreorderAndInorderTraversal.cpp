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
    int search(vector<int> pre, int val, int start, int end){
        int ans = -1;
        
        for(int i = start; i <= end; i++){
            if(pre[i] == val){
                ans = i;
                break;
            }
        }
        
        return ans;
    }
    
    TreeNode* build(vector<int>& pre, vector<int>& in, int start, int end, int& i){
        if(start > end){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(pre[i]);
        
        int pos = search(in, pre[i], start, end);
        
        i++;
        
        root->left = build(pre, in, start, pos-1, i);
        root->right = build(pre, in, pos+1, end, i);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        
        return build(preorder, inorder, 0, preorder.size()-1, i);
    }
};
