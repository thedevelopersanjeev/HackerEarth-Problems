class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> ans(s.size());
        for(int i = 0; i < s.size(); i++) {
            ans[indices[i]] = s[i];
        }
        string A = "";
        for(const auto &x : ans)
            A += x;
        return A;
    }
};