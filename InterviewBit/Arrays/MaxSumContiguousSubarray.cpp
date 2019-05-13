int Solution::maxSubArray(const vector<int> &A) {
    
    int n = A.size();
    
    if(n<=0)
            return 0;
        int maxSum = A[0];
        int sum = A[0];
        for(int i = 1; i<n; ++i)
        {
            if(sum < 0)
                sum = 0;
            sum += A[i];
            if(sum > maxSum)
                maxSum = sum;
        }
        
        return maxSum;
    
}
