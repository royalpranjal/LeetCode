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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newHead = NULL, *curr = head, *prev = NULL;
        
        while(curr){
            if(curr->val != val){
                if(newHead){
                    prev->next = curr;
                    prev = curr;
                }
                else{
                    newHead = curr;
                    prev = curr;
                }
            }
            curr = curr->next;
        }
        
        if(prev){
            prev->next = NULL;
        }
        
        return newHead;
    }
};
