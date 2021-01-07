class Solution {
  public:
	int lengthOfLongestSubstring(string s) {
		vector<int> freq(128, 0);
		int n = s.size(), ans = 0, prev = 0;
		for (int i = 0; i < n; i++) {
			prev = max(prev, freq[(int)s[i]]);
			ans = max(ans, i - prev + 1);
			freq[(int)s[i]] = i + 1;
		}
		return ans;
	}
};