int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    if(n == 1)
        return 0;
    sort(A.begin(), A.end());
    int ans = A[n-1] - A[0];
    int x = A[0] + B;
    int y = A[n-1] - B;
    if(x > y)
        swap(x, y);
    for(int i = 1; i < n-1; i++){
        int subtract = A[i] - B; 
        int add = A[i] + B;
        if (subtract >= x || add <= y) 
            continue;
        if (y - subtract <= add - x) 
            x = subtract; 
        else
            y = add;
    }
    return min(ans, y-x);
}
