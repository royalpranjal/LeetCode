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
        ListNode* newHead = NULL, *curr = head;
        
        while(curr){
            ListNode* temp = curr->next;
            
            while(temp && temp->val == curr->val){
                temp = temp->next;
            }
            curr->next = temp;
            
            if(!newHead){
                newHead = curr;
            }
            
            curr = temp;
        }
        
        return newHead;
    }
};
