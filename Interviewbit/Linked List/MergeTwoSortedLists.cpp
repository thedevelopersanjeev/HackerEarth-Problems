/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2){

    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    ListNode* ans = NULL;
    if(l1->val < l2->val){
        ans = l1;
        l1 = l1->next;
    }
    else{
        ans = l2;
        l2 = l2->next;
    }
    ListNode* temp = ans;
    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            temp->next = l1;
            l1 = l1->next;
        }
        else{
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    if(l1 != NULL)
        temp->next = l1;
    else
        temp->next = l2;
    return ans;

}
