class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> mp;
        for(const auto &ch : s) {
            mp[ch]++;
        }
        int cnt = 0;
        for(const auto &ele : mp) {
            if(ele.second % 2 == 1) {
                cnt++;
            }
        }
        return cnt <= 1;
    }
};