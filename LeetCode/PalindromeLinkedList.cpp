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
    bool isPalindrome(ListNode* A) {
        ListNode* head = A;
    stack<int> st;
    while(A != NULL){
        st.push(A->val);
        A = A->next;
    }
    while(head != NULL){
        int top = st.top();
        st.pop();
        if(head->val != top)
            return 0;
        head = head->next;
    }
    return 1;
    }
};