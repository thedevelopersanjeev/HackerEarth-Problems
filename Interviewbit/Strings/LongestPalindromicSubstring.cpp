string Solution::longestPalindrome(string s) {

	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
		if (i + 1 < n) {
			dp[i + 1][i] = 1;
		}
	}


}
