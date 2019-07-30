int Solution::solve(vector<int> &A) {

    // base cases
    if(A.size() == 1)
        return A[0];
        
    if(A.size() == 2)
        return A[0] + A[1];
    
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // add all elements to min heap from given array
    for(auto ele : A)
        pq.push(ele);
        
    // pick minimum length ropes and replace them with their sum into the heap
    // keep doing this until the size of heap becomes 2
    
    int ans = 0;
    
    while(pq.size() > 2){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        ans += x;
        ans += y;
        pq.push(x+y);
    }
    
    int x = pq.top();
    pq.pop();
    int y = pq.top();
    pq.pop();
    ans += x;
    ans += y;
    return ans;
    
}