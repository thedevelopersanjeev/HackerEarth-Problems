class Solution {
public:
    
    int getRow(char ch) {
        ch = tolower(ch);
        if(ch == 'q' || ch == 'w' || ch == 'e' || ch == 'r' || ch == 't' || ch == 'y' || ch == 'u' || ch == 'i' || ch == 'o' || ch == 'p') {
            return 0;
        } else if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'f' || ch == 'g' || ch == 'h' || ch == 'j' || ch == 'k' || ch == 'l') {
            return 1;
        } else {
            return 2;
        }
    }
    
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for(const auto &word : words) {
            vector<int> cnt(3, 0);
            for(const auto &ch : word) {
                int x = getRow(ch);
                cnt[x]++;
            }
            if((cnt[0] == 0 && cnt[1] == 0) || (cnt[1] == 0 && cnt[2] == 0) || (cnt[0] == 0 && cnt[2] == 0)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};