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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum;
        ListNode* head = NULL;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* curr = head;
        
        while(curr1 != NULL || curr2 != NULL){
            if(curr1 != NULL && curr2 != NULL){
                sum = curr1->val + curr2->val + carry;
            }
            else if(curr1 != NULL){
                sum = curr1->val + carry;
            }
            else if(curr2 != NULL){
                sum = curr2->val + carry;
            }
            carry = sum/10;
            sum = sum%10;
            ListNode* temp = new ListNode(sum);
            if(head == NULL){
                curr = temp;
                head = temp;
            }
            else{
                curr->next = temp;
                curr = curr->next;
            }
            if(curr1 != NULL){
                curr1 = curr1->next;
            }
            if(curr2 != NULL){
                curr2 = curr2->next;
            }
        }
        
        if(carry != 0){
            ListNode* temp = new ListNode(carry);
            curr->next = temp;
        }
        
        return head;
    }
};
