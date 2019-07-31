class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto ele : nums)
            pq.push(ele);
        for(int i = 1; i < k; i++)
            pq.pop();
        return pq.top();
    }
};