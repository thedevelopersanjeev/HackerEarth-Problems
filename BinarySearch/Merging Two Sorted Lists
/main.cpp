vector<int> solve(vector<int> &a, vector<int> &b) {
	int n = a.size(), m = b.size(), i = 0, j = 0;
	vector<int> ans;
	ans.reserve(n + m);
	while (i < n && j < m) {
		if (a[i] < b[j]) {
			ans.push_back(a[i]);
			i++;
		} else {
			ans.push_back(b[j]);
			j++;
		}
	}
	while (i < n) {
		ans.push_back(a[i]);
		i++;
	}
	while (j < m) {
		ans.push_back(b[j]);
		j++;
	}
	return ans;
}