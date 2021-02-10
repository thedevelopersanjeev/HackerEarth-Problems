/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        ListNode* node = dummy;
        stack<int> st;
        while (head != nullptr) {
            int cnt = k;
            while (head != nullptr && cnt--) {
                st.push(head->val);
                head = head->next;
            }
            if (head == nullptr && cnt > 0) {
                vector<int> temp;
                while (!st.empty()) {
                    temp.push_back(st.top());
                    st.pop();
                }
                reverse(temp.begin(), temp.end());
                for (const auto& ele : temp) {
                    node->next = new ListNode(ele);
                    node = node->next;
                }
                break;
            }
            while (!st.empty()) {
                node->next = new ListNode(st.top());
                st.pop();
                node = node->next;
            }
        }
        return dummy->next;
    }
};