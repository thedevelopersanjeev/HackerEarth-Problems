class Solution {
public:

    string f(string s) {
        string ans;
        for (auto ch : s) {
            if (ch != '#') {
                ans += ch;
            }
            else if (ans.size() > 0) {
                ans = ans.substr(0, ans.size() - 1);
            }
        }
        return ans;
    }

    bool backspaceCompare(string S, string T) {

        return f(S) == f(T);

    }
};