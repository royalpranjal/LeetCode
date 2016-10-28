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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* curr = head, *prev = NULL, *temp = NULL;
        
        if(head == NULL){
            return head;
        }
        
        int count = 1;
        
        while(count != m){
            prev = curr;
            curr = curr->next;
            count++;
        }
        
        ListNode* start = curr;
        ListNode* bef = prev;
        
        prev = curr;
        curr = curr->next;
        
        while(count != n && curr != NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            
            count++;
        }
        
        ListNode* h = head;
        
        start->next = curr;
        
        if(bef == NULL){
            h = prev;
        }
        else{
            bef->next = prev;
        }
        
        return h;
    }
};
