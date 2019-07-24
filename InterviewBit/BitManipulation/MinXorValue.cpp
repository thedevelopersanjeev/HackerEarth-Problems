int Solution::findMinXor(vector<int> &A) {
    sort(begin(A), end(A));
    int ans = INT_MAX;
    for(int i = 0; i < A.size() - 1; i++)
        ans = min(ans, A[i]^A[i+1]);
    return ans;
}
