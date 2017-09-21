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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return head;
        }    
        
        ListNode *prev = NULL, *curr = head;
        
        while(curr){
            ListNode* temp = curr;
            int count = 0;
            while(temp->next && temp->val == (temp->next)->val){
                count++;
                temp = temp->next;
            }
            if(!count){
                if(!prev){
                    head = temp;    
                }
                else{
                    prev->next = temp;
                }
                prev = temp;    
            }
            curr = temp->next;
        }
        
        if(!prev){
            return NULL;
        }
        
        prev->next = NULL;
        
        return head;
    }
};
