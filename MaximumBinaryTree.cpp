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
    int index(vector<int>& nums, int start, int end){
        int maxi = start;
        for(int i = start+1; i <= end; i++){
            if(nums[i] > nums[maxi]){
                maxi = i;
            }
        }
        
        return maxi;
    }
    
    TreeNode* makeTree(vector<int>& nums, int start, int end){
        if(start > end){
            return NULL;
        }
        
        int maxi = index(nums, start, end);
        
        TreeNode* root = new TreeNode(nums[maxi]);
        
        root->left = makeTree(nums, start, maxi-1);
        root->right = makeTree(nums, maxi+1, end);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return makeTree(nums, 0, nums.size()-1);    
    }
};
