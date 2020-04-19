bool isArrAbsent(vector<vector<int>> &ans, vector<int> &arr) {
	for (auto ele : ans) {
		if (ele == arr) {
			return false;
		}
	}
	return true;
}

vector<vector<int>> Solution::threeSum(vector<int> &arr) {

	long long n = arr.size();
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
	for (long long i = 0; i < n - 1; i++) {
		long long lo = i + 1;
		long long hi = n - 1;
		while (lo < hi) {
			long long curr = (long long)arr[i] + (long long)arr[lo] + (long long)arr[hi];
			if (curr == 0) {
				vector<int> temp = {arr[i], arr[lo], arr[hi]};
				if (isArrAbsent(ans, temp))
					ans.push_back(temp);
				lo++;
				hi--;
			}
			else if (curr > 0) {
				hi--;
			}
			else {
				lo++;
			}
		}
	}
	return ans;

}
