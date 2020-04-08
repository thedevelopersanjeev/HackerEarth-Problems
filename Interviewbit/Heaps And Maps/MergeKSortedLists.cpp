/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::mergeKLists(vector<ListNode*> &arr) {
    multiset<int> st;
    for(auto l : arr) {
    	while(l != NULL) {
    		st.insert(l->val);
    		l = l->next;
    	}
    }
    ListNode* head = new ListNode(0);
    ListNode* ans = head;
    for(auto ele : st) {
    	ListNode* temp = new ListNode(ele);
    	head->next = temp;
    	head = head->next;
    }
    return ans->next;
}
