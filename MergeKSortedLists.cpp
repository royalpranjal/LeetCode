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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size(), i = 0;
        
        priority_queue<int, vector<int>, greater<int> > q;
        
        while(i < n){
            ListNode* curr = lists[i];
            
            while(curr){
                q.push(curr->val);
                curr = curr->next;
            }
            
            i++;
        }
        
        ListNode* head = NULL, *curr = NULL;
        
        while(!q.empty()){
            ListNode* temp = new ListNode(q.top());
            if(!head){
                head = temp;
                curr = temp;
            }
            else{
                curr->next = temp;
                curr = temp;
            }
            q.pop();
        }
        
        return head;
    }
};
