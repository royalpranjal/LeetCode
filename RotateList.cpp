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
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode* curr = head;
        ListNode* nhead = NULL;
        ListNode* prev = NULL;
        
        if(curr == NULL || k == 0 || curr->next == NULL){
            return curr;
        }
        
        int len = 0;
        
        while(curr != NULL){
            len++;
            curr = curr->next;
        }
        
        if(k >= len){
            k = k%len;
        }
        
        if(k == 0){
            return head;
        }
        
        len = len - k;
        
        curr = head;
        
        while(len){
            prev = curr;
            curr = curr->next;
            len--;
        }
        
        prev->next = NULL;
        
        nhead = curr;
        
        while(curr != NULL){
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = head;
        
        return nhead;
        
    }
};
