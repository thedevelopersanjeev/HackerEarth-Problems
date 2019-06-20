int Solution::maxArea(vector<int> &A) {

    int r = A.size() - 1, l = 0;
    
    int ans = 0;
    
    while(l < r){
        
        ans = max(ans, (r-l)*min(A[l], A[r]));
        
        if(A[l] < A[r])
            l++;
        
        else
            r--;
        
    }
    
    return ans;
}