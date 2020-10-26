class Solution {
   public:
    vector<string> commonChars(vector<string> &A) {
        vector<string> ans;
        vector<int> mp(26, INT_MAX);
        for (const auto &ele : A) {
            vector<int> curr(26, 0);
            for (const auto &ch : ele) {
                curr[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                mp[i] = min(mp[i], curr[i]);
            }
        }
        for (int i = 0; i < 26; i++) {
            while (mp[i]--) ans.push_back(string(1, i + 'a'));
        }
        return ans;
    }
};