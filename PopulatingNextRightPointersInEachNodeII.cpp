/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL){
            return;
        }   
        
        if(root->left != NULL){
            if(root->right != NULL){
                (root->left)->next = root->right;
            }
            else{
                TreeLinkNode* temp = root;
                while(temp->next != NULL){
                    if((temp->next)->left != NULL){
                        (root->left)->next = (temp->next)->left;
                        break;
                    }
                    else if((temp->next)->right != NULL){
                        (root->left)->next = (temp->next)->right;
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
        
        if(root->right != NULL){
            TreeLinkNode* temp = root;
            while(temp->next != NULL){
                if((temp->next)->left != NULL){
                    (root->right)->next = (temp->next)->left;
                    break;
                }
                else if((temp->next)->right != NULL){
                    (root->right)->next = (temp->next)->right;
                    break;
                }
                temp = temp->next;
            }
        }
        
        connect(root->right);
        connect(root->left);
    }
};
