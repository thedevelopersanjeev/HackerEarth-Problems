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

ListNode* Solution::rotateRight(ListNode* l, int k){

    int len = findLength(l);
    k = k%len;
    if(k == 0)
        return l;
    

}
