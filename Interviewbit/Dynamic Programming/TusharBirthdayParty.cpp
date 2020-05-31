int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
	int a = A.size(), b = B.size(), c = C.size(), mx = *max_element(A.begin(), A.end()), ans = 0;
	vector<vector<int>> dp(mx + 1, vector<int>(b, 0));
	for (int i = 1; i <= mx; i++)
		dp[i][0] = (i % B[0] == 0) ? C[0] * (i / B[0]) : INT_MAX;
	for (int i = 1; i <= mx; i++)
		for (int j = 1; j < b; j++)
			dp[i][j] = min(dp[i][j - 1], (i - B[j] >= 0 && dp[i - B[j]][j] != INT_MAX) ? (dp[i - B[j]][j] + C[j]) : (INT_MAX));
	for (int i = 0; i <= a; i++)
		ans += dp[A[i]][b - 1];
	return ans;
}
