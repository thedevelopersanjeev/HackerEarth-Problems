/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* l){

    ListNode* curr = l;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    while(curr != NULL){
        // store next pointer
        next = curr->next;
        // reverse current node
        curr->next = prev;
        // move the pointers one ahead
        prev = curr;
        curr = next;
    }
    return prev;

}
