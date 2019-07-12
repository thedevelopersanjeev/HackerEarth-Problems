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
        
        ListNode *aSlow = head;
        ListNode *aFast = head;
        
        while (aFast != NULL && aFast->next != NULL) {
            aFast = aFast->next->next;
            aSlow = aSlow->next;
            if (aFast == aSlow) { break; }
        }
        
        if (aFast == NULL || aFast->next == NULL) { return NULL; }
        
        aSlow = head;
        while (aSlow != aFast) {
            aFast = aFast->next;
            aSlow = aSlow->next;
        }

        return aFast;
        
    }
};