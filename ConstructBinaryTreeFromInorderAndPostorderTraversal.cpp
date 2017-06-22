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
    int get(vector<int>& inorder, int start, int end, int value){
        for(int i = start; i <= end; i++){
            if(inorder[i] == value){
                return i;
            }
        }
        
        return -1;
    }

    TreeNode* make(vector<int>& inorder, int inS, int inE, vector<int>& postorder, int pS, int pE){
        if(inS > inE || inS < 0 || inE >= inorder.size()){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[pE]);
        
        int index = get(inorder, inS, inE, root->val);
        
        root->left = make(inorder, inS, index-1, postorder, pS, pS+(index-inS-1));
        root->right = make(inorder, index+1, inE, postorder, pE-(inE-index), pE-1);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inS = 0, inE = inorder.size()-1, pS = 0, pE = postorder.size()-1;
        
        return make(inorder, inS, inE, postorder, pS, pE);
    }
};
