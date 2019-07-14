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
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        
        int l1 = 0;
    int l2 = 0;
    ListNode* temp = A;
    while(temp != NULL){
        l1++;
        temp = temp->next;
    }
    temp = B;
    while(temp != NULL){
        l2++;
        temp = temp->next;
    }
    if(l1 > l2){
        int d = l1 - l2;
        while(d--){
            A = A->next;
        }
        while(1){
            if(A == B)
                return A;
            A = A->next;
            B = B->next;
        }
    }
    else{
        int d = l2 - l1;
        while(d--){
            B = B->next;
        }
        while(1){
            if(A == B)
                return A;
            A = A->next;
            B = B->next;
        }
    }
        
    }
};