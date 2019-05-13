int Solution::solve(vector<int> &A) {
    int n = A.size();
    for(int i = 1; i < n-1; i++)
        if(A[i] > A[i-1] && A[i] > A[i+1])
            return A[i];
    if(A[0] > A[1])
        return A[0];
    if(A[n-1] > A[n-2])
        return A[n-1];
}
