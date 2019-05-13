int Solution::solve(vector<int> &A) {
    int n = A.size();
    int count = 0;
    for(int i = 0; i < n; i++)
        if(A[i]%2 == 0)
            count++;
    return min(count, n - count);
}
