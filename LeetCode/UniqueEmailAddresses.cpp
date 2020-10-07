class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<pair<string, string>> st;
        for (auto &email : emails) {
            string curr = "";
            string domain = "";
            int n = email.size();
            for (int i = 0; i < n; i++) {
                if (email[i] == '+' || email[i] == '@') {
                    break;
                } else if (email[i] == '.') {
                    continue;
                } else {
                    curr += email[i];
                }
            }
            bool passed = false;
            for (const auto &ch : email) {
                if (passed) {
                    domain += ch;
                } else if (ch == '@') {
                    passed = true;
                }
            }
            st.insert({curr, domain});
        }
        return st.size();
    }
};