int solve(vector<int> &prices) {
	int mn = INT_MAX, ans = 0;
	for (const auto &price : prices) {
		mn = min(mn, price);
		ans = max(ans, price - mn);
	}
	return ans;
}