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
    void reverseList(ListNode* &l){
        ListNode* curr = l, *prev = NULL;

        while(curr){
            ListNode* temp = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        l = prev;
    }
    
    void print(ListNode* l){
        while(l){
            cout << l->val << " ";
            l = l->next;
        }
        
        cout << endl;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        reverseList(l1);
        reverseList(l2);
       
        ListNode *head = NULL, *curr = NULL;
        
        int carry = 0;
        
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            
            ListNode* temp = new ListNode(sum%10);
            
            carry = sum/10;
            
            if(!head){
                head = temp;
                curr = temp;
            }
            else{
                curr->next = temp;
                curr = temp;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1){
            int sum = l1->val + carry;
            
            ListNode* temp = new ListNode(sum%10);
            
            carry = sum/10;
            
            if(!head){
                head = temp;
                curr = temp;
            }
            else{
                curr->next = temp;
                curr = temp;
            }
            
            l1 = l1->next;
        }
        
        while(l2){
            int sum = l2->val + carry;
            
            ListNode* temp = new ListNode(sum%10);
            
            carry = sum/10;
            
            if(!head){
                head = temp;
                curr = temp;
            }
            else{
                curr->next = temp;
                curr = temp;
            }
            
            l2 = l2->next;
        }
        
        if(carry){
            ListNode* temp = new ListNode(carry);
            
            curr->next = temp;
            
            curr = temp;
        }
        
        reverseList(head);
        
        return head;
    }
};
