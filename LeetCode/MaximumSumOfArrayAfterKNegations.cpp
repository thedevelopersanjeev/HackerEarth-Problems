class Solution {
public:
    int largestSumAfterKNegations(vector<int>& arr, int k) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
    // insert all elements into the heap
    for(auto ele : arr)
        pq.push(ele);
    // perform negations on minimum element k times
    while(k--){
        int temp = pq.top();
        pq.pop();
        pq.push((-1) * temp);
    }
    // find sum of elements of heap
    int ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    return ans;
        
    }
};