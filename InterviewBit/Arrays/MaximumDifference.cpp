int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    sort(A.begin(), A.end());
    int total = accumulate(A.begin(), A.end(), 0);
    int temp1 = 0, temp2 = 0;
    for(int i = 0; i < B; i++)
        temp1 += A[i];
    for(int i = n-1; B != 0; i--, B--)
        temp2 += A[i];
    int ans1 = abs(temp1 - (total - temp1));
    int ans2 = abs(temp2 - (total - temp2));
    return max(ans1, ans2);
}
sss