void reverse(vector<int> &nums, int i, int j) {
	while (i < j) {
		swap(nums[i], nums[j]);
		i++;
		j--;
	}
}

vector<int> solve(vector<int> &nums, int k) {
	// first k to end
	// left shift last n - k
	// a[0:k-1] + a[k:n-1] => a[k:n-1] + a[0:k-1]
	// a[n-1:k] + a[k-1:0] => a[k:n-1] + a[0:k-1]
	int n = nums.size();
	reverse(nums, 0, k - 1);
	reverse(nums, k, n - 1);
	reverse(nums, 0, n - 1);
	return nums;
}