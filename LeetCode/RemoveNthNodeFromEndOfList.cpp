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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 0; i < n; i++)
            fast = fast->next;
        // if it is the first node to be removed
        // or n is size of list
        // fast reaches the end of list
        // and hence, fast should point to NULL
        if(fast == NULL){
            head = head->next;
            return head;
        }
        // now, move fast till it reaches the end
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        // now, slow points to nth node from the end
        slow->next = slow->next->next;
        return head;
    }
};