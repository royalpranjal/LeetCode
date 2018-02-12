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
    void dfs(TreeNode* root, priority_queue<int>& q){
        if(!root){
            return;
        }
        
        q.push(root->val);
        dfs(root->left, q);
        dfs(root->right, q);
    }
    
    int minDiffInBST(TreeNode* root) {
        priority_queue<int> q;
        dfs(root, q);
        
        int last = 0, ans = INT_MAX;
        
        while(!q.empty()){
            ans = min(ans, abs(q.top() - last));
            last = q.top();
            q.pop();
        }
        
        return ans;
    }
};
