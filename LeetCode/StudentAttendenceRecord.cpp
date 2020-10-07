class Solution {
public:
    bool checkRecord(string s) {
        bool ok = true;
        int n = s.size();
        for(int i = 0; i < n - 2; i++) {
            if(s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L') {
                ok = false;
            }
        }
        int cnt = 0;
        for(const auto &ele : s) {
            if (ele == 'A') {
                cnt++;
            }
        }
        return ok && cnt <= 1;
    }
};