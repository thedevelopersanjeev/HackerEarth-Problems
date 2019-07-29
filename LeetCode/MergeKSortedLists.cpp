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
    ListNode* mergeKLists(vector<ListNode*>& A) {
        
        
        priority_queue<int, vector<int>, greater<int>> pq;
    for(auto ele : A){
        while(ele != NULL){
            pq.push(ele->val);
            ele = ele->next;
        }
    }
    ListNode* ans = NULL;
    ListNode* curr = ans;
    while(!pq.empty()){
        auto ele = pq.top();
        pq.pop();
        if(ans == NULL){
            ans = new ListNode(ele);
            //curr = curr->next;   
            curr = ans;
        }
        else{
            curr->next = new ListNode(ele);
            curr = curr->next;
        }
    }
    
    return ans;
        
    }
};