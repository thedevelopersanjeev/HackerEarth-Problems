class Solution {
  public:
	int numSubarraysWithSum(vector<int> &A, int S) {
		map<int, int> mp;
		mp[0] = 1;
		int ans = 0, curr = 0;
		for (const auto &ele : A) {
			curr += ele;
			ans += mp[curr - S];
			mp[curr]++;
		}
		return ans;
	}
};