class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        int n = s.size();
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == '+' && s[i + 1] == '+') {
                string t = s;
                t[i] = '-';
                t[i + 1] = '-';
                ans.push_back(t);
            }
        }
        return ans;
    }
};