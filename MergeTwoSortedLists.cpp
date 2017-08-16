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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL, *curr = NULL;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                ListNode* temp1 = l1->next;
                if(!curr){
                    head = l1;
                    curr = l1;
                }
                else{
                    curr->next = l1;    
                    curr = curr->next;
                }
                l1 = temp1;
            }
            else{
                ListNode* temp2 = l2->next;
                if(!curr){
                    head = l2;
                    curr = l2;
                }
                else{
                    curr->next = l2;
                    curr = curr->next;
                }
                l2 = temp2;
            }
        }
        
        if(!head){
            if(l1){
                head = l1;
            }
            else{
                head = l2;
            }
        }
        else{
            if(l1){
                curr->next = l1;
            }
            else if(l2){
                curr->next = l2;
            }
        }
        
        return head;
    }
};
