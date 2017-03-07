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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = NULL, *curr = head, *evenHead = NULL, *oddCurr = NULL, *evenCurr = NULL;
        
        int count = 1;
        
        while(curr){
            if(count%2 == 0){
                if(!evenHead){
                    evenHead = curr;
                    evenCurr = curr;
                }
                else{
                    evenCurr->next = curr;
                    evenCurr = curr;
                }
            }
            else{
                if(!oddHead){
                    oddHead = curr;
                    oddCurr = curr;
                }
                else{
                    oddCurr->next = curr;
                    oddCurr = curr;
                }
            }
            count++;
            curr = curr->next;
        }
        
        if(oddCurr){
            oddCurr->next = evenHead;
        }
        if(evenCurr){
            evenCurr->next = NULL;
        }
        
        return oddHead;
    }
};
