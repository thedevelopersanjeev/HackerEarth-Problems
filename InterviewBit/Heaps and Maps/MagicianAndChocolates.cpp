int Solution::nchoc(int A, vector<int> &B) {

    priority_queue<int> pq;
    
    for(auto ele : B)
        pq.push(ele);
    
    long long ans = 0;
    
    while(A--){
        
        int temp = pq.top();
        pq.pop();
        ans = (ans + temp) % 1000000007;
        pq.push(floor(temp/2));
        
    }
    
    return ans;

}