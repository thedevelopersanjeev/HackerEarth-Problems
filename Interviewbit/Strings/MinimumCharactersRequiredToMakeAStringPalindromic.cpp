int Solution::solve(string s) {

	int n = s.size();
	if(n == 0) {
		return 0;
	}
	// string till res is a palindrome...
	// then, answer can be n - res
	int res = 1;
	for(int i = 1; i < n; i++) {
		// check if string from 0 to i is a palindrome??
		int lo = 0, hi = i;
		bool isPalindrome = true;
		while(lo < hi) {
			if(s[lo] != s[hi]) {
				isPalindrome = false;
				break;
			}
			lo++;
			hi--;
		}
		// update res, larger palindrome prefix found
		if(isPalindrome) {
			res = i + 1;
		}
	}
	return n - res;

}
