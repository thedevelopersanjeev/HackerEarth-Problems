/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* l){

    stack<int> st;
    ListNode* temp = l;
    while(temp != NULL){
        st.push(temp->val);
        temp = temp->next;
    }
    while(!st.empty()){
        if(st.top() != l->val)
            return 0;
        l = l->next;
        st.pop();
    }
    return 1;

}
