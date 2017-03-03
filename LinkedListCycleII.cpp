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
    ListNode *detectCycle(ListNode *head) {
        ListNode* ans = NULL, *slow = head, *fast = head;
        
        do{
            if(slow == NULL || fast == NULL){
                return ans;
            }
            if(fast->next == NULL){
                return ans;
            }
            slow = slow->next;
            fast = (fast->next)->next;
        }while(slow != fast);
        
        while(slow != head){
            slow = slow->next;
            head = head->next;
        }
        
        return slow;
    }
};
