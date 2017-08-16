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
    void inorder(TreeNode* root, vector<int>& in){
        if(!root){
            return;
        }
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    
    int find(vector<int>& in, int key){
        int start = 0, end = in.size()-1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            if(in[mid] == key){
                return mid;
            }
            else if(in[mid] > key){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        return -1;
    }
    
    TreeNode* make(TreeNode* root, vector<int>& in, vector<int>& sumV){
        if(!root){
            return NULL;
        }
        
        int index = find(in, root->val);
        root->val = sumV[index];
        
        root->left = make(root->left, in, sumV);
        root->right = make(root->right, in, sumV);
        
        return root;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        vector<int> in;
        inorder(root, in);
        
        vector<int> sumV(in.size(), 0);
        
        int sum = 0;
        
        for(int i = in.size()-1; i >= 0; i--){
            sum += in[i];
            sumV[i] = sum;
        }
        
        return make(root, in, sumV);
    }
};
