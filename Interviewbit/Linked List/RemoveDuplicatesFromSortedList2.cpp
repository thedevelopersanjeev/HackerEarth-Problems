/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::deleteDuplicates(ListNode* l){

    if(l == NULL || l->next == NULL)
        return l;
    
    ListNode* ans = new ListNode(0);
    ans->next = l;
    ListNode* curr = ans;
    ListNode* temp;
    while(curr->next != NULL){
        temp = curr->next;
        while(temp->next != NULL && temp->val == temp->next->val)
            temp = temp->next;
        if(curr->next == temp){
            curr = curr->next;
        }
        else{
            curr->next = temp->next;
        }
    }
    return ans->next;

}
