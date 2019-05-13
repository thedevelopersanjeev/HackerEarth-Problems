int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    int ans = INT_MAX;
    int n = A.size();
    for(int i = 1; i < n; i++)
        ans = min(ans, A[i]-A[i-1]);
    return ans;
}
