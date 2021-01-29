class Solution {
  public:
	string minWindow(string s, string t) {
		unordered_map<char, int> mp;
		for (const auto &ch : t) {
			mp[ch]++;
		}
		int cnt = t.size(), i = 0, j = 0, len = 1e9, st = 0;
		while (j < s.size()) {
			if (mp[s[j++]]-- > 0) {
				cnt--;
			}
			while (cnt == 0) {
				if (j - i < len) {
					len = j - i;
					st = i;
				}
				if (mp[s[i++]]++ == 0) {
					cnt++;
				}
			}
		}
		return len == 1e9 ? "" : s.substr(st, len);
	}
};