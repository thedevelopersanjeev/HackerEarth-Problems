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
    bool hasCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
    
    while(fast != NULL && slow != NULL && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            return 1;
        }
    }
    
    return 0;
        
    }
};