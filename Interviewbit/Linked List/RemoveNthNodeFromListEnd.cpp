/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int findLength(ListNode* l){
    int ans = 0;
    while(l != NULL){
        ans++;
        l = l->next;
    }
    return ans;
}

ListNode* Solution::removeNthFromEnd(ListNode* l, int n){

    int len = findLength(l);
    if(n >= len)
        return l->next;
    if(n == 0)
        return l;
    ListNode* temp = l;
    int d = len - n;
    for(int i = 1; i < d; i++)
        temp = temp->next;
    if(temp->next != NULL)
        temp->next = temp->next->next;
    return l;

}
