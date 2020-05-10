vector<int> Solution::findSubstring(string A, const vector<string> &B) {

	if (A.size() == 0 || B.size() == 0) {
		return vector<int> {};
	}
	vector<string> C = B;
	vector<int> ans;
	int i = 0, j = B.size() * B[0].size();
	while (j < A.size()) {

		i++;
		j++;
	}

}
