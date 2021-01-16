vector<int> solve(vector<int> &nums) {
	vector<int> ans;
	int i = 0, j = nums.size() - 1;
	ans.reserve(j + 1);
	while (i <= j) {
		int x = nums[i] * nums[i];
		int y = nums[j] * nums[j];
		if (x > y) {
			ans.push_back(x);
			i++;
		} else {
			ans.push_back(y);
			j--;
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}