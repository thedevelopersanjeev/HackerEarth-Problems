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
    ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
        
        // final answer
    ListNode* head = NULL;
    
    // if A is null, answer is B
    if(A == NULL)
        return B;
        
    // if B is null, answer is A
    if(B == NULL)
        return A;
        
    // recursive call
    if(A->val <= B->val){
        head = A;
        head->next = mergeTwoLists(A->next, B);
    }
    
    // recursive call
    else{
        head = B;
        head->next = mergeTwoLists(A, B->next);
    }
    
    return head;
        
    }
};