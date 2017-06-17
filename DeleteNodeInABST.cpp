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
    TreeNode* get(TreeNode* root, int key){
        if(!root){
            return NULL;
        }
        if(root->val == key){
            return root;
        }
        else if(root->val > key){
            return get(root->left, key);
        }
        return get(root->right, key);
    }
    
    TreeNode* getSuc(TreeNode* root){
        TreeNode* curr = root->right;

        while(curr->left){
            curr = curr->left;
        }
                
        return curr;
    }
    
    TreeNode* getParent(TreeNode* root, TreeNode* key, bool& left){
        if(!root){
            return NULL;
        }
        else if(root->left == key){
            left = true;
            return root;
        }
        else if(root->right == key){
            return root;
        }
        else if(root->val < key->val){
            return getParent(root->right, key, left);
        }
        return getParent(root->left, key, left);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* node = get(root, key);
        
        if(!node){
            return root;
        }
        
        bool left = false;
        TreeNode* parent = getParent(root, node, left);
        
        if(!node->left && !node->right){
            if(parent){
                if(left){
                    parent->left = NULL;
                }
                else{
                    parent->right = NULL;
                }
            }
            else{
                return NULL;
            }
        }
        else if(!node->left){
            if(parent){
                if(left){
                    parent->left = node->right;
                }
                else{
                    parent->right = node->right;
                }
            }
            else{
                return node->right;    
            }
        }
        else if(!node->right){
            if(parent){
                if(left){
                    parent->left = node->left;
                }
                else{
                    parent->right = node->left;
                }
            }
            else{
                return node->left;    
            }
        }
        else{
            TreeNode* successor = getSuc(node);
            successor->left = node->left;
            
            bool lft = false;
            TreeNode* succParent = getParent(root, successor, lft);
            
            if(succParent){
                if(lft){
                    succParent->left = successor->right;
                }
                else{
                    succParent->right = successor->right;
                }
            }
            
            successor->right = node->right;
            
            if(parent){
                if(left){
                    parent->left = successor;
                }
                else{
                    parent->right = successor;
                }
            }
            else{
                return successor;    
            }
        }
        
        return root;
    }
};
