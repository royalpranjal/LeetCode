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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = head, *smallHead = NULL, *small = NULL, *bigHead = NULL, *big = NULL;
        
        while(curr){
            if(curr->val < x){
                if(smallHead){
                    small->next = curr;
                    small = curr;
                }
                else{
                    smallHead = curr;
                    small = smallHead;
                }
            }
            else{
                if(bigHead){
                    big->next = curr;
                    big = curr;
                }
                else{
                    bigHead = curr;
                    big = bigHead;
                }
            }
            curr = curr->next;
        }
        
        if(big){
            big->next = NULL;    
        }
        if(small){
            small->next = bigHead;
            return smallHead;
        }
        
        return bigHead;
    }
};
