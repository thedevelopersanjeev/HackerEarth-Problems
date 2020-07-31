string Solution::getPermutation(int n, int k) {

	string s = "", ans = "";
	vector<long long> factorial(n + 1, 1LL);
	long long sum = 1LL;
	for (long long i = 1LL; i <= n; i++) {
		s.push_back(i + '0');
		sum *= i;
		factorial[i] = sum;
	}
	k--;
	for (long long i = 1LL; i <= n; i++) {
		long long index = k / factorial[n - i];
		ans.push_back(s[index]);
		s.erase(s.begin() + index);
		k %= factorial[n - i];
	}
	return ans;

}