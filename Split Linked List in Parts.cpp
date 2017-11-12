/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode* root){
        int len = 0;
        
        while(root){
            len++;
            root = root->next;
        }
        
        return len;
    }
    
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans;
        
        int len = getLen(root);
        int actual = len/k, extra = len%k;
        
        if(actual){
            while(root){
                int curr = actual;
                ans.push_back(root);
                ListNode* temp = root;
                while(temp && curr > 1){
                    temp = temp->next;
                    curr--;
                }

                if(extra){
                    temp = temp->next;
                    extra--;
                }

                root = temp->next;
                temp->next = NULL;
            }
        }
        else{
            while(root && k){
                ListNode* temp = root->next;
                root->next = NULL;
                ans.push_back(root);
                root = temp;
                k--;
            }

            while(k){
                ans.push_back(NULL);
                k--;
            }
        }
        
        return ans;
    }
};
