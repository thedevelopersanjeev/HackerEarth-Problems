class KthLargest {
    public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int mK;
    KthLargest(int k, vector<int>& nums) {
        mK = k;
        for(int & v : nums){
            if(pq.size() == k){
                if(v < pq.top())
                    continue;
                pq.pop();
                pq.push(v);
            }
            else pq.push(v);
        }
    }
    
    int add(int val) {
        
        if(pq.size() < mK){
            pq.push(val);
            return pq.top();
        }
        
        if(val > pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */